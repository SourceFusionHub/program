// Define data structures
interface BlogPost {
  id: number;
  title: string;
  content: string;
  categoryIds: number[];
  tagIds: number[];
}

interface Category {
  id: number;
  name: string;
}

interface Tag {
  id: number;
  name: string;
}

// Initialize data
let nextPostId = 1;
let nextCategoryId = 1;
let nextTagId = 1;

const blogPosts: BlogPost[] = [];
const categories: Category[] = [];
const tags: Tag[] = [];

// CRUD operations for Blog Posts
function createBlogPost(title: string, content: string, categoryIds: number[], tagIds: number[]): BlogPost {
  const newPost: BlogPost = {
    id: nextPostId++,
    title,
    content,
    categoryIds,
    tagIds,
  };
  blogPosts.push(newPost);
  return newPost;
}

function readBlogPost(id: number): BlogPost | undefined {
  return blogPosts.find((post) => post.id === id);
}

function updateBlogPost(id: number, updatedData: Partial<BlogPost>): BlogPost | undefined {
  const postIndex = blogPosts.findIndex((post) => post.id === id);
  if (postIndex !== -1) {
    blogPosts[postIndex] = { ...blogPosts[postIndex], ...updatedData };
    return blogPosts[postIndex];
  }
  return undefined;
}

function deleteBlogPost(id: number): boolean {
  const postIndex = blogPosts.findIndex((post) => post.id === id);
  if (postIndex !== -1) {
    blogPosts.splice(postIndex, 1);
    return true;
  }
  return false;
}

// CRUD operations for Categories
function createCategory(name: string): Category {
  const newCategory: Category = {
    id: nextCategoryId++,
    name,
  };
  categories.push(newCategory);
  return newCategory;
}

function readCategory(id: number): Category | undefined {
  return categories.find((category) => category.id === id);
}

function updateCategory(id: number, updatedData: Partial<Category>): Category | undefined {
  const categoryIndex = categories.findIndex((category) => category.id === id);
  if (categoryIndex !== -1) {
    categories[categoryIndex] = { ...categories[categoryIndex], ...updatedData };
    return categories[categoryIndex];
  }
  return undefined;
}

function deleteCategory(id: number): boolean {
  const categoryIndex = categories.findIndex((category) => category.id === id);
  if (categoryIndex !== -1) {
    categories.splice(categoryIndex, 1);
    return true;
  }
  return false;
}

// CRUD operations for Tags
function createTag(name: string): Tag {
  const newTag: Tag = {
    id: nextTagId++,
    name,
  };
  tags.push(newTag);
  return newTag;
}

function readTag(id: number): Tag | undefined {
  return tags.find((tag) => tag.id === id);
}

function updateTag(id: number, updatedData: Partial<Tag>): Tag | undefined {
  const tagIndex = tags.findIndex((tag) => tag.id === id);
  if (tagIndex !== -1) {
    tags[tagIndex] = { ...tags[tagIndex], ...updatedData };
    return tags[tagIndex];
  }
  return undefined;
}

function deleteTag(id: number): boolean {
  const tagIndex = tags.findIndex((tag) => tag.id === id);
  if (tagIndex !== -1) {
    tags.splice(tagIndex, 1);
    return true;
  }
  return false;
}
