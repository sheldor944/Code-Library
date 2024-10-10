import Foundation

if let url = URL(string: "https://www.apple.com") {
    let task = URLSession.shared.dataTask(with: url) { data, response, error in
        if let data = data {
            print("Data received: \(data)")
        }
    }
    task.resume()
}
