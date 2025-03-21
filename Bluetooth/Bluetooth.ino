#include <ArduinoBLE.h>
#include <PDM.h> // Include PDM library for microphone input

BLEService diagnosisService("12345678-1234-5678-1234-56789abcdef0");  // Custom BLE Service
BLEStringCharacteristic diagnosisCharacteristic("abcdef01-1234-5678-1234-56789abcdef0", 
                                                BLERead | BLENotify, 50); // Max 50 characters

#define BUFFER_SIZE 256
int16_t sampleBuffer[BUFFER_SIZE];
volatile bool newDataAvailable = false;

void onPDMdata() {
    PDM.read(sampleBuffer, BUFFER_SIZE);
    newDataAvailable = true;
}

void setup() {
    Serial.begin(115200);
    if (!BLE.begin()) {
        Serial.println("Failed to start BLE!");
        while (1);
    }
  
    BLE.setLocalName("RespiroCare");
    BLE.setAdvertisedService(diagnosisService);
    diagnosisService.addCharacteristic(diagnosisCharacteristic);
    BLE.addService(diagnosisService);
    BLE.advertise();

    Serial.println("BLE Service Started!");
    
    // Initialize PDM microphone
    PDM.begin(1, 16000); // Mono channel, 16 kHz sample rate
    PDM.setBufferSize(BUFFER_SIZE);
    PDM.onReceive(onPDMdata);
}

String classifyRespiratoryDisease(float feature1, float feature2, float feature3) {
    if (feature1 > 0.8) return "COPD Detected";
    if (feature2 > 0.7) return "Bronchiectasis Detected";
    if (feature3 > 0.6) return "Pneumonia Detected";
    if (feature1 < 0.3 && feature2 < 0.3) return "Healthy";
    if (feature3 < 0.4) return "Bronchiolitis Detected";
    return "URTI";
}

void loop() {
    BLEDevice central = BLE.central();
    if (central) {
        Serial.print("Connected to: ");
        Serial.println(central.address());

        // Process microphone data
        if (newDataAvailable) {
            float feature1 = 0, feature2 = 0, feature3 = 0;
            for (int i = 0; i < BUFFER_SIZE; i++) {
                feature1 += abs(sampleBuffer[i]);
            }
            feature1 = feature1 / BUFFER_SIZE / 32768.0; // Normalize amplitude
            feature2 = random(0, 100) / 100.0; // Placeholder for frequency-based features
            feature3 = random(0, 100) / 100.0; // Placeholder for spectral-based features
            
            newDataAvailable = false;

            String diagnosisResult = classifyRespiratoryDisease(feature1, feature2, feature3);

            // Send diagnosis via BLE
            diagnosisCharacteristic.writeValue(diagnosisResult);
            Serial.println("Diagnosis Sent: " + diagnosisResult);
        }
        
        delay(5000); // Send every 5 seconds
    }
}
