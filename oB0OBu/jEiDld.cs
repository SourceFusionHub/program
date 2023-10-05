using System;
using System.Speech.Synthesis;

class Program
{
    static void Main()
    {
        SpeechSynthesizer synth = new SpeechSynthesizer();

        // Subscribe to the event to handle speech synthesis progress
        synth.SpeakProgress += Synth_SpeakProgress;

        // Prompt the user for text input
        Console.Write("Enter text to synthesize: ");
        string inputText = Console.ReadLine();

        // Synthesize and speak the entered text
        synth.SpeakAsync(inputText);

        // Keep the program running to allow for real-time synthesis
        Console.WriteLine("Press Enter to exit.");
        Console.ReadLine();
    }

    private static void Synth_SpeakProgress(object sender, SpeakProgressEventArgs e)
    {
        // Display the current synthesis progress
        Console.WriteLine($"Synthesizing: {e.Text} ({e.CharacterPosition} out of {e.CharacterCount} characters)");
    }
}
