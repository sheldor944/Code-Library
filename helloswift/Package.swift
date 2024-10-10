// swift-tools-version:5.5
import PackageDescription

let package = Package(
    name: "WeatherApp",
    dependencies: [
        .package(url: "https://github.com/scinfu/SwiftSoup.git", from: "2.3.2"),
        .package(url: "https://github.com/Alamofire/Alamofire.git", from: "5.4.0")
    ],
    targets: [
        .target(
            name: "WeatherApp",
           dependencies: ["SwiftSoup", "Alamofire"]),

    ]
)
