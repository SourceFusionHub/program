<?php

class RBAC {
    private $roles;
    private $permissions;
    private $rolePermissions;

    public function __construct() {
        $this->roles = [];
        $this->permissions = [];
        $this->rolePermissions = [];
    }

    // Create a new role
    public function createRole($roleName) {
        if (!isset($this->roles[$roleName])) {
            $this->roles[$roleName] = [];
        }
    }

    // Define a permission
    public function createPermission($permissionName) {
        if (!isset($this->permissions[$permissionName])) {
            $this->permissions[$permissionName] = true;
        }
    }

    // Assign a permission to a role
    public function assignPermissionToRole($permissionName, $roleName) {
        if (isset($this->roles[$roleName]) && isset($this->permissions[$permissionName])) {
            $this->roles[$roleName][$permissionName] = true;
        }
    }

    // Check if a user with specific roles has a permission
    public function hasPermission($userRoles, $permissionName) {
        foreach ($userRoles as $role) {
            if (isset($this->roles[$role]) && isset($this->roles[$role][$permissionName])) {
                return true;
            }
        }
        return false;
    }
}

// Example usage:
$rbac = new RBAC();

// Create roles
$rbac->createRole("Admin");
$rbac->createRole("Editor");
$rbac->createRole("Viewer");

// Define permissions
$rbac->createPermission("CreatePost");
$rbac->createPermission("EditPost");
$rbac->createPermission("DeletePost");

// Assign permissions to roles
$rbac->assignPermissionToRole("CreatePost", "Admin");
$rbac->assignPermissionToRole("EditPost", "Admin");
$rbac->assignPermissionToRole("DeletePost", "Admin");
$rbac->assignPermissionToRole("EditPost", "Editor");
$rbac->assignPermissionToRole("CreatePost", "Editor");
$rbac->assignPermissionToRole("CreatePost", "Viewer");

// Check if a user has a permission
$userRoles = ["Admin", "Editor"];
if ($rbac->hasPermission($userRoles, "CreatePost")) {
    echo "User has permission to create posts.";
} else {
    echo "User does not have permission to create posts.";
}
