import Foundation

func getWordMeaning(word: String) {
    let urlString = "https://www.dictionary.com/browse/\(word)"
    guard let url = URL(string: urlString) else {
        print("Invalid URL")
        return
    }

    let task = URLSession.shared.dataTask(with: url) { data, response, error in
        if let error = error {
            print("Error fetching data: \(error)")
            return
        }

        guard let data = data else {
            print("No data found")
            return
        }

        if let htmlContent = String(data: data, encoding: .utf8) {
            // Extracting the meaning from the HTML content
            if let startRange = htmlContent.range(of: "<meta name=\"description\" content=\"") {
                let subString = htmlContent[startRange.upperBound...]
                if let endRange = subString.range(of: "\">") {
                    let meaning = subString[..<endRange.lowerBound]
                    print("Meaning of \(word): \(meaning)")
                    return
                }
            }
            print("Meaning not found in the HTML content.")
        }
    }
    task.resume()
}

// Example usage
getWordMeaning(word: "swift")
