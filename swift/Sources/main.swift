import Foundation

let people: [String: [String]] = [
    // Alice has 7 mutual friends with Bob
    "Alice": ["Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Heidi", "Ivan", "Judy"],
    "Bob": ["Alice", "Charlie", "David", "Eve", "Frank", "Grace", "Heidi", "Karl", "Larry"],
    
    // Charlie has 5 mutual friends with David
    "Charlie": ["Alice", "Bob", "David", "Eve", "Frank", "Mallory", "Nina", "Oscar", "Peggy", "Quincy"],
    "David": ["Alice", "Bob", "Charlie", "Eve", "Frank", "Roger", "Sybil", "Trent", "Ursula", "Victor"],
    
    // Eve and Frank have 3 mutual friends
    "Eve": ["Alice", "Bob", "Charlie", "David", "Frank", "Walter", "Xavier", "Yvonne", "Zara"],
    "Frank": ["Alice", "Bob", "Charlie", "David", "Eve", "Chris", "Diane", "Edward", "Fiona", "George"],
    
    // Grace and Heidi have 3 mutual friends
    "Grace": ["Alice", "Bob", "Charlie", "David", "Ivan", "Heidi", "Hannah", "Ian", "Jasmine", "Kevin"],
    "Heidi": ["Alice", "Bob", "Charlie", "David", "Ivan", "Grace", "Liam", "Mia", "Nathan", "Olivia"],
    
    // Remaining people have no more than 1 mutual friend
    "Ivan": ["Alice", "Grace", "Heidi", "Peter", "Quentin", "Rachel", "Sam", "Tina", "Uma", "Vince"],
    "Judy": ["Alice", "Bob", "Charlie", "Wendy", "Xander", "Yasmin", "Zane", "Aaron", "Beth", "Carl"]
]

func mutualFriendsCount(person1: String, person2: String) -> Int? {
    guard let friends1 = people[person1], let friends2 = people[person2] else {
        return nil
    }
    let mutualFriends = Set(friends1).intersection(friends2)
    return mutualFriends.count
}

print("hello")