'''
Problem: Library Management System
Problem Statement:

Design a library management system that supports the following features:

Borrowing and Returning Books:
Users should be able to borrow books from the library if they are available.
Users should be able to return books they have borrowed.

Tracking Books:
The system should keep track of how many copies of each book are available.
The system should track which user has borrowed which book.

User Management:
Users should be able to register with the library.
The system should keep track of which users are registered.

Book Management:
Admins should be able to add new books to the library.
Admins should be able to remove books from the library.

Functionality:
Users can borrow and return books.
Admins can add or remove books from the library.
The system should track the availability of books and users who have borrowed them.

Classes to Implement:
Book
User
Library
Admin

Requirements:
Implement the borrow_book method that allows a user to borrow a book if it's available.
Implement the return_book method that allows a user to return a borrowed book.
Implement the add_book and remove_book methods in the Library class to manage the library's inventory.
Implement a register_user method to add new users to the library system.
'''

class Book:
    def __init__(self, title, author, count) -> None:
        self.__title = title
        self.__author = author
        self.__count = count
        
    def is_available(self) -> bool:
        return self.__count > 0
    
    def borrow(self) -> bool:
        if self.__count == 0:
            return False
        self.__count -= 1
        return True
    
    def get_title(self) -> str:
        return self.__title
    
    def get_author(self) -> str:
        return self.__author
    
    def get_available_count(self) -> int:
        return self.__count
    
    def update_count(self, count) -> int:
        self.__count += count
        return self.__count

class User:
    def __init__(self, user_id) -> None:
        self.__user_id = user_id
        self.__checked_out_books = set()
        
    def borrow_book(self, title, author) -> bool:
        if (title, author) in self.__checked_out_books:
            # Already borrowed
            return False
        self.__checked_out_books.add((title, author))
        return True
    
    def return_book(self, title, author) -> bool:
        if (title, author) not in self.__checked_out_books:
            # Already borrowed
            return False
        self.__checked_out_books.pop((title, author))
        return True
    
    def get_user_id(self) -> str:
        return self.__user_id
    
    def get_total_borrowed_book(self) -> int:
        return len(self.__checked_out_books)

class Admin:
    def __init__(self) -> None:
        # users by user_id
        self.__users = {}
        self.__next_user_id = 0
        
    def add_new_user(self) -> int:
        user_id = self.__next_user_id
        self.__users[user_id] = User(self.__next_user_id)
        self.__next_user_id += 1
        return user_id
        
    def borrow_book(self, user_id, title, author) -> bool:
        if user_id not in self.__users:
            return False
        return self.__users[user_id].borrow_book(title, author)
    
    def return_book(self, user_id, title, author)
        if user_id not in self.__users:
            return False
        return self.__users[user_id].return_book(title, author)

class Library(Admin):
    def __init__(self) -> None:
        # Books by title, author
        self.__books = {}
        
    def add_book_to_library(self, title, author, count):
        if (title, author) in self.__books:
            self.__books[(title, author)].update_count(count)
        self.__books[(title, author)] = Book(title, author, count)