# RespiroCare: Real-Time Respiratory Disease Detection and Classification

## 🚀 Overview
**RespiroCare** is an AI-powered respiratory disease detection system designed for rural patients. Using an **Arduino Nano 33** and machine learning, the system analyzes cough sounds in real-time to detect and classify potential respiratory conditions. This low-cost, portable solution aims to enhance early diagnosis and healthcare accessibility in underserved areas.

## 🛠️ Features
- **Real-time analysis** of cough patterns.
- **AI-powered classification** of respiratory diseases.
- **Arduino Nano 33 integration** for portable and efficient data collection.
- **User-friendly interface** for easy interpretation of results.
- **Affordable and accessible** solution for rural healthcare.

## 📦 Installation
### 1️⃣ Clone the Repository
```bash
 git clone https://github.com/codeshark304/RespiraCare-Real-Time-Respiratory-Disease-Detection-and-Classification-using-Arduino-Nano33.git
 cd RespiroCare
```
### 2️⃣ Install Dependencies
```bash
pip install -r requirements.txt  # Install Python dependencies
```
### 3️⃣ Set Up the Arduino Nano 33
- Install the necessary libraries in the **Arduino IDE**.
- Upload the provided firmware to the Arduino Nano 33.

## ▶️ Usage
1. Power on the Arduino Nano 33 and connect it to the system.
2. The patient **coughs into the device**.
3. The AI model **analyzes the sound in real time**.
4. Results are displayed, indicating potential respiratory conditions.

##  Dataset Information
- **Dataset Source**: [Kaggle - Respiratory Sound Database](https://www.kaggle.com/vbookshelf/respiratory-sound-database)
- **Creators**: Research teams from Portugal and Greece
- **Total Recordings**: 920 (varying length: 10s to 90s)
- **Patients**: 126
- **Total Duration**: 5.5 hours
- **Respiratory Cycles**: 6898
  - 1864 contain crackles
  - 886 contain wheezes
  - 506 contain both crackles and wheezes

The dataset includes both **clean respiratory sounds** and **noisy recordings** simulating real-life conditions. Patients span all age groups: **children, adults, and the elderly**.

##  Dataset Contents
- **920** `.wav` sound files
- **920** annotation `.txt` files
- A text file listing the diagnosis for each patient
- A text file explaining the file naming format
- A text file listing **91 filename corrections** (`filename_differences.txt`)
- A text file containing demographic details for each patient

 **Note:** `filename_differences.txt` lists corrected filenames due to an earlier bug in the dataset's naming script. It can now be ignored.

---

##  Sound Clips Processing & Image Preprocessing

- **Sound Processing**: Utilized **Librosa** ([Librosa Library](https://librosa.github.io/librosa/)) for feature extraction.
- **Spectrogram Generation**: Sound clips were converted into **spectrogram images**.
- **Image Resizing**: Resized to **0.72 x 0.72** and uniformly scaled.
- **Data Variability**: Spectrograms exhibit differences based on various sound sources and case conditions.

 These preprocessing steps ensure that the data is ready for AI model training and respiratory condition classification.



