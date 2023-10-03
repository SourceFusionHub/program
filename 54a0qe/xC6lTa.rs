extern crate reqwest;
extern crate serde;
extern crate serde_json;
extern crate whatlang;

use reqwest::blocking::Client;
use serde::{Deserialize, Serialize};
use whatlang::{detect, Lang};

// Define a struct to represent the Yandex.Translate API response
#[derive(Debug, Serialize, Deserialize)]
struct TranslationResponse {
    text: Vec<String>,
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    // Yandex.Translate API key (replace with your API key)
    let api_key = "YOUR_API_KEY";

    // Text to translate
    let text_to_translate = "Hello, world!";

    // Detect the language of the input text
    let lang = detect(text_to_translate).unwrap_or(Lang::Eng);

    // Translate the text to a different language (e.g., Spanish)
    let target_lang = "es"; // Spanish
    let translation_url = format!(
        "https://translate.yandex.net/api/v1.5/tr.json/translate?key={}&text={}&lang={}-{}",
        api_key, text_to_translate, lang, target_lang
    );

    let client = Client::new();
    let response = client.get(&translation_url).send()?;
    let response_text = response.text()?;

    // Parse the translation response
    let translation: TranslationResponse = serde_json::from_str(&response_text)?;

    // Extract the translated text
    let translated_text = translation.text.join(" ");

    println!("Input Text: {}", text_to_translate);
    println!("Detected Language: {:?}", lang);
    println!("Translated Text ({}): {}", target_lang, translated_text);

    Ok(())
}
