#include <stdio.h>
int book_ticket()
{
    static int ticket_sold = 0;
    ticket_sold++;
    return ticket_sold;
}
int main()
{
    int count;
    count = book_ticket ();
    count = book_ticket ();
    printf("Sold %d\n", count);
    return 0;
}
