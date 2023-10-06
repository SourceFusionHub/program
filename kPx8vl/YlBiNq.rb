#In order to paarse the website we need to download the Nokogiri Gem by using the following command
gem install nokogiri

require 'nokogiri'
require 'open-uri'

# Here the url of the website that is needed to scrap is specified
url = 'http://url.com/'

# To Fetch the HTML content of the page
html = URI.open(url)

# To Parse the HTML content using Nokogiri 
#In order to download the Nokogiri
doc = Nokogiri::HTML(html)

# Extract data from the page
quotes = []

doc.css('div.quote').each do |quote_element|
  text = quote_element.css('span.text').text
  author = quote_element.css('span small.author').text
  tags = quote_element.css('div.tags a.tag').map(&:text)

  # Store the data in a hash
  quote_data = {
    text: text,
    author: author,
    tags: tags
  }

  quotes << quote_data
end

# To Print the scraped data
quotes.each_with_index do |quote, index|
  puts "Quote #{index + 1}:"
  puts "Text: #{quote[:text]}"
  puts "Author: #{quote[:author]}"
  puts "Tags: #{quote[:tags].join(', ')}"
  puts "\n"
end
