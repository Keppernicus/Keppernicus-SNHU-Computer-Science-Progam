//=====================================================================
// Name        : ProjectTwo.cpp
// Author      : Chris Koepp
// Version     : 1.0
// Description : Module 7 final project, with Binary Search Trees (BST)
//=====================================================================

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#pragma region ForwardDeclarations
//=======================================================
// Function Declarations
//=======================================================


void LoadData(std::string filename);
void PrintAllCourses();
void PrintCourseInfo(std::string coursenumber);
void Menu();
#pragma endregion
#pragma region StructsAndClasses
//=======================================================
// structs and classes
//=======================================================

struct Course
{
    std::string courseNumber;
    std::string title;
    std::vector<std::string> prereqs;
};

/*
 *Define my BST, the members, and the functions to implement it
 */
class BinarySearchTree
{
private:
    // create a node struct to hold the course and it's children to the left and right
    struct Node
    {
        Course course;
        Node* left;
        Node* right;

        // the constructor to initialize a node with a course
        Node(const Course& c);
    };

    Node* root;

    void addNode(Node* node, const Course& course);
    void inOrder(Node* node) const;
    Course* search(Node* node, const std::string& courseNumber) const;
    void destroyTree(Node* node);


	public:
    BinarySearchTree();
    ~BinarySearchTree();

    void Insert(const Course& course);
    void PrintInOrder() const;
    Course* Search(const std::string& courseNumber) const;

};

// Define the node constructor
BinarySearchTree::Node::Node(const Course& c) : course(c), left(nullptr), right(nullptr) {}

// BST Constructor
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

// BST Destructor
BinarySearchTree::~BinarySearchTree()
{
    destroyTree(root);
}

// recursive node destructor
void BinarySearchTree::destroyTree(Node* node)
{
	if (node != nullptr)
	{
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
	}
}

// BST insert
void BinarySearchTree::Insert(const Course& course)
{
	if (root == nullptr)
	{
        root = new Node(course);
	} else
	{
        addNode(root, course);
	}
}

// Recursive inserter
void BinarySearchTree::addNode(Node* node, const Course& course)
{
	if (course.courseNumber < node->course.courseNumber)
	{
		if (node->left == nullptr)
		{
            node->left = new Node(course);
		} else
		{
            addNode(node->left, course);
		}

	} else
	{
		if (node->right == nullptr)
		{
            node->right = new Node(course);
		} else
		{
            addNode(node->right, course);
		}
	}
}

// Print, the inOrder traversal
void BinarySearchTree::PrintInOrder() const
{
    inOrder(root);
}

// inOrder traversal, recursively
void BinarySearchTree::inOrder(Node* node) const
{
    if (node == nullptr) return;
    inOrder(node->left);
    std::cout << node->course.courseNumber << ", " << node->course.title << std::endl;
    inOrder(node->right);
}

// Search
Course* BinarySearchTree::Search (const std::string& courseNumber) const
{
    return search(root, courseNumber);
}

// Recursively search
Course* BinarySearchTree::search(Node* node, const std::string& courseNumber) const
{
    if (node == nullptr) {
    	return nullptr;
    }
    if (node->course.courseNumber == courseNumber) {
        return &node->course;
    }
    if (courseNumber < node->course.courseNumber) {
        return search(node->left, courseNumber);
    }
    else {
        return search(node->right, courseNumber);
    }

}


BinarySearchTree courseTree;


// Function to load the data

void LoadData(std::string filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Cannot open file.\n";
        return;
    }

    std::string line;
    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string token;
        Course course;

        //get the course number
        getline(ss, course.courseNumber, ',');

        //get the title
        getline(ss, course.title, ',');

        //get the prereqs
        while (getline(ss, token, ','))
        {
            course.prereqs.push_back(token);
        }
        courseTree.Insert(course);	    
    }
    file.close();
    std::cout << "Data loaded successfully.\n";
}

// Function to print all courses
void PrintAllCourses()
{
    courseTree.PrintInOrder();
}

// print the course info
void PrintCourseInfo(std::string courseNumber)
{
    //normalize the input first
    std::transform(courseNumber.begin(), courseNumber.end(), courseNumber.begin(), ::toupper);

    Course* course = courseTree.Search(courseNumber);
    if (course ==nullptr)
    {
        std::cout << "Course not found.\n";
        return;
    }

    std::cout << course->courseNumber << ", " << course->title << std::endl;

    if (course->prereqs.empty()) {
        std::cout << "No prerequisites.\n";
    } else
    {
        std::cout << "Prerequisites: ";
        for (const std::string& prereq : course->prereqs)
        {
            std::cout << prereq << " ";
        }
        std::cout << std::endl;
    }
}



#pragma endregion

void Menu()
{
    int choice = -1;
    std::string filename;
    std::string input;
    do
    {
        // menu options display output
        std::cout << "\n---  Welcome to the course planner. ---\n"
            << "1. Load Data Structure.\n"
            << "2. Print Course List.\n"
            << "3. Print Course.\n"
            << "9. Exit\n"
            << "What would you like to do?: ";
        std::cin >> choice;
        // switch cases for the choices and validation
        try
        {
            switch (choice)
            {
            case 1:
                std::cout << "Enter file name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, filename);
                LoadData(filename);
                break;
            case 2:
                PrintAllCourses();
                break;
            case 3:
                std::cout << "Enter course number: ";
                std::cin >> input;
                PrintCourseInfo(input);
                break;
            case 9:
                std::cout << "Thank you for using the course planner!\n" << std::flush;
                break;
            default:
                throw std::out_of_range("Invalid option. Please try again.");
            }

        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            choice = -1; // Put the user back into the menu instead of closing out
        }
    } while (choice != 9);
}




//=======================================================
// Main Function
//=======================================================

int main()
{
    Menu();
    return 0;

}
