#include <stdio.h>

typedef struct _node {
    char left;
    char right;
} Node;

Node node[26];

void PreOrder(char n)
{
    if (n + 'A' == '.') return;

    printf("%c", n + 'A');
    PreOrder(node[n].left - 'A');
    PreOrder(node[n].right - 'A');
}

void InOrder(char n)
{
    if (n + 'A' == '.') return;

    InOrder(node[n].left - 'A');
    printf("%c", n + 'A');
    InOrder(node[n].right - 'A');
}

void PostOrder(char n)
{
    if (n + 'A' == '.') return;

    PostOrder(node[n].left - 'A');
    PostOrder(node[n].right - 'A');
    printf("%c", n + 'A');
}

int main()
{
    char root, left, right;
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c %c %c", &root, &left, &right);
        node[root - 'A'].left = left;
        node[root - 'A'].right = right;
    }

    PreOrder(0);
    putchar('\n');
    InOrder(0);
    putchar('\n');
    PostOrder(0);
    putchar('\n');

    return 0;
}