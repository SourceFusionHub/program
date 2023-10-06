'''
you have to install pkg-
1.speech_recognition
2. pyaudio
3.FLAC
and get your google API key
'''
import speech_recognition as sr

def recognize_speech():
    # Initialize the recognizer
    recognizer = sr.Recognizer()

    # Capture audio from the microphone
    with sr.Microphone() as source:
        print("Say something...")
        recognizer.adjust_for_ambient_noise(source)  # Adjust for ambient noise
        audio = recognizer.listen(source)

    try:
        # Recognize the speech using Google Web Speech API
        text =recognizer.recognize_google(audio, key="YOUR_GOOGLE_API_KEY")
        print("You said: " + text)
    except sr.UnknownValueError:
        print("Sorry, I couldn't understand what you said.")
    except sr.RequestError as e:
        print("Could not request results from Google Web Speech API; {0}".format(e))

if __name__ == "__main__":
    recognize_speech()
