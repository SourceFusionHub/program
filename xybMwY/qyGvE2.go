package main

import (
	"time"
)

type BlogPost struct {
	Title   string
	Content string
	Created time.Time
}

type Blog struct {
	Posts []BlogPost
}

func (b *Blog) CreatePost(title, content string) {
	post := BlogPost{
		Title:   title,
		Content: content,
		Created: time.Now(),
	}
	b.Posts = append(b.Posts, post)
}

func (b *Blog) UpdatePost(index int, content string) error {
	if index < 0 || index >= len(b.Posts) {
		return fmt.Errorf("Invalid post index")
	}
	b.Posts[index].Content = content
	return nil
}

func (b *Blog) DeletePost(index int) error {
	if index < 0 || index >= len(b.Posts) {
		return fmt.Errorf("Invalid post index")
	}
	b.Posts = append(b.Posts[:index], b.Posts[index+1:]...)
	return nil
}

func (b *Blog) ListPosts() {
	fmt.Println("Blog Posts:")
	for i, post := range b.Posts {
		fmt.Printf("Post %d:\n", i+1)
		fmt.Printf("Title: %s\n", post.Title)
		fmt.Printf("Content: %s\n", post.Content)
		fmt.Printf("Created: %s\n", post.Created.Format("2006-01-02 15:04:05"))
		fmt.Println("------------------------")
	}
}

func main() {
	myBlog := Blog{}

	myBlog.CreatePost("First Post", "This is the content of the first blog post.")
	myBlog.CreatePost("Second Post", "This is the content of the second blog post.")

	// Update the first post
	err := myBlog.UpdatePost(0, "Updated content of the first blog post.")
	if err != nil {
		fmt.Println(err)
	}

	// Delete the second post
	err = myBlog.DeletePost(1)
	if err != nil {
		fmt.Println(err)
	}
}
