using System;
using System.Collections.Generic;

class RecommendationService
{
    // Simulated user profiles and recommendations for demonstration purposes.
    private Dictionary<int, List<int>> userProfiles = new Dictionary<int, List<int>>();
    private Dictionary<int, List<int>> recommendations = new Dictionary<int, List<int>>();

    public RecommendationService()
    {
        // Initialize user profiles and recommendations (you would load these from your data store).
        userProfiles[1] = new List<int> { 101, 102, 103 };
        userProfiles[2] = new List<int> { 101, 104, 105 };
        recommendations[1] = new List<int> { 201, 202, 203 };
        recommendations[2] = new List<int> { 204, 205, 206 };
    }

    public List<int> GetRecommendations(int userId)
    {
        if (recommendations.ContainsKey(userId))
        {
            return recommendations[userId];
        }
        else
        {
            return new List<int>(); // Return an empty list if no recommendations are available.
        }
    }
}

class Program
{
    static void Main()
    {
        RecommendationService recommendationService = new RecommendationService();

        // Get recommendations for user ID 1.
        List<int> user1Recommendations = recommendationService.GetRecommendations(1);
        Console.WriteLine("Recommendations for User 1: " + string.Join(", ", user1Recommendations));

        // Get recommendations for user ID 3 (no recommendations available).
        List<int> user3Recommendations = recommendationService.GetRecommendations(3);
        Console.WriteLine("Recommendations for User 3: " + string.Join(", ", user3Recommendations));
    }
}
