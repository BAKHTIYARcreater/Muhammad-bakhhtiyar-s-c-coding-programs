#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid_username(const char *u)
{
    if (strlen(u) != 5)
        return 0;
    for (int i = 0; u[i]; ++i)
    {
        if (!isalpha((unsigned char)u[i]))
            return 0;
    }
    return 1;
}

int is_valid_password(const char *p)
{
    if (strlen(p) != 6)
        return 0;

    int hasUpper = 0, hasLower = 0, hasDigit = 0;
    for (int i = 0; p[i]; ++i)
    {
        if (isupper((unsigned char)p[i]))
            hasUpper = 1;
        else if (islower((unsigned char)p[i]))
            hasLower = 1;
        else if (isdigit((unsigned char)p[i]))
            hasDigit = 1;
    }
    return hasUpper && hasLower && hasDigit;
}

int main()
{
    char username[100], password[100];

    printf("=== User Registration ===\n");

    while (1)
    {
        printf("Enter username (exactly 5 alphabets): ");
        if (scanf("%99s", username) != 1)
            return 0;
        if (!is_valid_username(username))
        {
            printf("Invalid username. Try again.\n");
            continue;
        }
        break;
    }

    while (1)
    {
        printf("Enter password (6 chars, 1 upper, 1 lower, 1 digit): ");
        if (scanf("%99s", password) != 1)
            return 0;
        if (!is_valid_password(password))
        {
            printf("Invalid password. Try again.\n");
            continue;
        }
        break;
    }

    printf("Account Created Successfully.\n");

    printf("\n=== Login ===\n");

    char uname_try[100], pass_try[100];
    while (1)
    {
        printf("Username: ");
        if (scanf("%99s", uname_try) != 1)
            return 0;
        printf("Password: ");
        if (scanf("%99s", pass_try) != 1)
            return 0;

        if (strcmp(uname_try, username) == 0 && strcmp(pass_try, password) == 0)
        {
            printf("Welcome %s, you are now logged in.\n", username);
            break;
        }
        else
        {
            printf("Incorrect username or password. Try again.\n");
        }
    }

    return 0;
}

