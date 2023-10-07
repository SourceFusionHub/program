interface Rating {
  userId: string;
  itemId: string;
  rating: number;
}

interface UserItemMatrix {
  [userId: string]: {
    [itemId: string]: number;
  };
}

function collaborativeFiltering(ratings: Rating[], targetUserId: string): string[] {
  // Step 1: Create a user-item matrix
  const userItemMatrix: UserItemMatrix = {};

  ratings.forEach((rating) => {
    const { userId, itemId, rating: userRating } = rating;

    if (!userItemMatrix[userId]) {
      userItemMatrix[userId] = {};
    }

    userItemMatrix[userId][itemId] = userRating;
  });

  // Step 2: Find similar users
  const similarities: { [userId: string]: number } = {};

  Object.keys(userItemMatrix).forEach((userId) => {
    if (userId !== targetUserId) {
      let sum = 0;

      Object.keys(userItemMatrix[targetUserId]).forEach((itemId) => {
        if (userItemMatrix[userId][itemId]) {
          sum += Math.pow(userItemMatrix[userId][itemId] - userItemMatrix[targetUserId][itemId], 2);
        }
      });

      similarities[userId] = 1 / (1 + Math.sqrt(sum));
    }
  });

  // Step 3: Recommend items
  const recommendedItems: { [itemId: string]: number } = {};

  Object.keys(similarities).forEach((userId) => {
    Object.keys(userItemMatrix[userId]).forEach((itemId) => {
      if (!userItemMatrix[targetUserId][itemId]) {
        if (!recommendedItems[itemId]) {
          recommendedItems[itemId] = 0;
        }

        recommendedItems[itemId] += similarities[userId] * userItemMatrix[userId][itemId];
      }
    });
  });

  // Step 4: Sort and return recommended items
  const sortedRecommendedItems = Object.keys(recommendedItems).sort(
    (a, b) => recommendedItems[b] - recommendedItems[a]
  );

  return sortedRecommendedItems;
}

// Example usage
const ratings: Rating[] = [
  { userId: 'user1', itemId: 'item1', rating: 5 },
  { userId: 'user1', itemId: 'item2', rating: 4 },
  { userId: 'user2', itemId: 'item1', rating: 3 },
  { userId: 'user2', itemId: 'item2', rating: 5 },
  { userId: 'user3', itemId: 'item2', rating: 4 },
];

const recommendedItems = collaborativeFiltering(ratings, 'user3');
console.log('Recommended Items:', recommendedItems);
