import Foundation

// Define a structure to represent user preferences (user-item ratings)
struct UserPreferences {
    let userId: String
    let preferences: [String: Double] // Item ID to rating mapping
}

// Define a structure to represent item recommendations
struct ItemRecommendation {
    let itemId: String
    let score: Double
}

// Create a function to generate item recommendations for a user
func generateRecommendations(forUser user: UserPreferences, data: [UserPreferences]) -> [ItemRecommendation] {
    // Compute item recommendations using a simple algorithm (e.g., item-based collaborative filtering)
    var itemScores: [String: Double] = [:]

    for otherUser in data {
        if otherUser.userId != user.userId {
            for (itemId, rating) in otherUser.preferences {
                // Calculate the score based on user similarity (e.g., cosine similarity)
                if user.preferences[itemId] == nil {
                    itemScores[itemId, default: 0.0] += rating
                }
            }
        }
    }

    // Sort items by their scores in descending order
    let sortedItems = itemScores.sorted { $0.value > $1.value }

    // Return top N recommendations (e.g., top 5 items)
    let topN = 5
    let recommendations = sortedItems.prefix(topN).map { ItemRecommendation(itemId: $0.key, score: $0.value) }

    return recommendations
}

// Example data: User preferences
let user1 = UserPreferences(userId: "user1", preferences: ["item1": 5.0, "item2": 4.0, "item3": 2.0])
let user2 = UserPreferences(userId: "user2", preferences: ["item1": 3.0, "item2": 4.0, "item4": 5.0])
let user3 = UserPreferences(userId: "user3", preferences: ["item2": 5.0, "item3": 4.0, "item5": 3.0])

let allUserPreferences = [user1, user2, user3]

// Generate recommendations for a specific user
let targetUser = UserPreferences(userId: "targetUser", preferences: ["item1": 4.0, "item4": 2.0, "item5": 3.0])

let recommendations = generateRecommendations(forUser: targetUser, data: allUserPreferences)

// Print recommendations
print("Recommendations for \(targetUser.userId):")
for recommendation in recommendations {
    print("\(recommendation.itemId) (Score: \(recommendation.score))")
}
