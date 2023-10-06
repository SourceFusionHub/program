import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

class User {
    private final String username;
    private final List<Post> posts;
    private final List<Comment> comments;

    public User(String username) {
        this.username = username;
        this.posts = new ArrayList<>();
        this.comments = new ArrayList<>();
    }

    public String getUsername() {
        return username;
    }

    public List<Post> getPosts() {
        return posts;
    }

    public List<Comment> getComments() {
        return comments;
    }
}

class Post {
    private static int postCounter = 1;

    private final int postId;
    private final String content;
    private final User author;
    private final List<Comment> comments;
    private int likes;

    public Post(String content, User author) {
        this.postId = postCounter++;
        this.content = content;
        this.author = author;
        this.comments = new ArrayList<>();
        this.likes = 0;
    }

    public int getPostId() {
        return postId;
    }

    public String getContent() {
        return content;
    }

    public User getAuthor() {
        return author;
    }

    public List<Comment> getComments() {
        return comments;
    }

    public int getLikes() {
        return likes;
    }

    public void addLike() {
        likes++;
    }

    public void addComment(Comment comment) {
        comments.add(comment);
    }
}

class Comment {
    private static int commentCounter = 1;

    private final int commentId;
    private final String content;
    private final User author;

    public Comment(String content, User author) {
        this.commentId = commentCounter++;
        this.content = content;
        this.author = author;
    }

    public int getCommentId() {
        return commentId;
    }

    public String getContent() {
        return content;
    }

    public User getAuthor() {
        return author;
    }
}

public class SocialMediaPlatform {
    private final Map<String, User> users;
    private final List<Post> posts;

    public SocialMediaPlatform() {
        this.users = new HashMap<>();
        this.posts = new ArrayList<>();
    }

    public User createUser(String username) {
        User newUser = new User(username);
        users.put(username, newUser);
        return newUser;
    }

    public void createPost(User author, String content) {
        Post newPost = new Post(content, author);
        posts.add(newPost);
        author.getPosts().add(newPost);
    }

    public void likePost(User user, Post post) {
        post.addLike();
    }

    public void commentOnPost(User user, Post post, String content) {
        Comment newComment = new Comment(content, user);
        post.addComment(newComment);
        user.getComments().add(newComment);
    }

    public void displayPosts() {
        System.out.println("All Posts:");
        for (Post post : posts) {
            System.out.println("Post ID: " + post.getPostId());
            System.out.println("Author: " + post.getAuthor().getUsername());
            System.out.println("Content: " + post.getContent());
            System.out.println("Likes: " + post.getLikes());
            System.out.println("Comments:");
            for (Comment comment : post.getComments()) {
                System.out.println("  Comment ID: " + comment.getCommentId());
                System.out.println("  Author: " + comment.getAuthor().getUsername());
                System.out.println("  Content: " + comment.getContent());
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        SocialMediaPlatform platform = new SocialMediaPlatform();
        User user1 = platform.createUser("user1");
        User user2 = platform.createUser("user2");

        platform.createPost(user1, "Hello, this is my first post!");
        platform.createPost(user2, "Nice to meet you all!");

        platform.likePost(user1, platform.posts.get(0));
        platform.commentOnPost(user2, platform.posts.get(0), "Welcome!");

        platform.displayPosts();
    }
}
