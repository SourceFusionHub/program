bool isValidEmail(const std::string& email) {
    size_t atPos = email.find('@');
    if (atPos == std::string::npos || atPos == 0 || atPos == email.length() - 1) {
        return false;
    }

    size_t dotPos = email.find('.', atPos);
    if (dotPos == std::string::npos || dotPos == atPos + 1 || dotPos == email.length() - 1) {
        return false;
    }

    for (size_t i = 0; i < email.length(); ++i) {
        char c = email[i];
        if (!std::isalnum(c) && c != '.' && c != '-' && c != '_' && c != '@') {
            return false;
        }
    }

    return true;
}
