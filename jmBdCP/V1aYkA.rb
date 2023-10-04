require 'uri'

def valid_url_with_query?(url)
  begin
    uri = URI.parse(url)
    return uri.is_a?(URI::HTTP) && !uri.query.nil?
  rescue URI::InvalidURIError
    return false
  end
end

# Test cases
puts valid_url_with_query?('https://example.com/api?param1=value1&param2=value2') # true
puts valid_url_with_query?('https://example.com') # false
puts valid_url_with_query?('invalidurl') # false
