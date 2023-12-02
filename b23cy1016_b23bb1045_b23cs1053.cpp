#include <stdio.h>
#include <math.h>
#include <string.h>


// Function to solve a system of linear equations in two variables
void solveLinearSystem(double a1, double b1, double c1, double a2, double b2, double c2) {
    // Calculate the determinant
    double det = a1 * b2 - a2 * b1;

    // Check if the system is consistent and has a unique solution
    if (det != 0) {
        // Calculate the values of x and y
        double x = (c1 * b2 - c2 * b1) / det;
        double y = (a1 * c2 - a2 * c1) / det;

        // Print the solution
        printf("Solution: x = %.2f, y = %.2f\n", x, y);
    } else {
        // The system is either inconsistent or has infinitely many solutions
        if ((c1 * b2 - c2 * b1) == 0 && (a1 * c2 - a2 * c1) == 0) {
            printf("The system has infinitely many solutions.\n");
        } else {
            printf("The system is inconsistent and has no solution.\n");
        }
    }
}




// Function to solve a quadratic equation ax^2 + bx + c = 0
void solveQuadraticEquation(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Two real and distinct solutions:\n");
        printf("x1 = %.2lf\n", root1);
        printf("x2 = %.2lf\n", root2);
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        printf("One real solution:\n");
        printf("x = %.2lf\n", root);
    } else {
        printf("No real solutions.\n");
    }
}

int main() {
    int choice;
    printf("Equation Solver\n");
    
    while (1) {
        printf("Choose the type of equation to solve:\n");
        printf("1. Linear Equation in Two Variables\n");
        printf("2. Quadratic Equation\n");
        printf("3. Linear Equation in One Variable\n");
        printf("4. Exit\n");
        
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                double a1, b1, c1, a2, b2, c2;
                printf("Enter coefficients for the linear equation a1x + b1y = c1: ");
                scanf("%lf %lf %lf", &a1, &b1, &c1);
                printf("Enter coefficients for the linear equation a2x + b2y = c2: ");
                scanf("%lf %lf %lf", &a2, &b2, &c2);
                solveLinearSystem(a1, b1, c1, a2, b2, c2);
                break;
            }
            case 2: {
                double a, b, c;
                printf("Enter coefficients for the quadratic equation ax^2 + bx + c = 0: ");
                scanf("%lf %lf %lf", &a, &b, &c);
                solveQuadraticEquation(a, b, c);
                break;
            }
            case 3: {
                double a, b;
                printf("Enter coefficients for the linear equation ax + b = 0: ");
                scanf("%lf %lf", &a, &b);
                if (a == 0 && b == 0) {
                    printf("The equation is satisfied for all x (infinite solutions).\n");
                } else if (a == 0) {
                    printf("The equation has no solution.\n");
                } else {
                    double x = -b / a;
                    printf("Solution: x = %.2lf\n", x);
                }
                break;
            }
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}
