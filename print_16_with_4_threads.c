/**
 * Goal:
 * "print out the message 16 times with 4 omp threads that you believe is most simple and 
 * efficient"
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void Hello_threads(int thread_count);

int main(int argc, char *argv[])
{
    int thread_count=4; // good default for ecc-linux

    if(argc < 2)
        printf("usage: print_16_with_4_threads <number threads>\n");
    else
    {
        sscanf(argv[1], "%d", &thread_count);
    }

    printf("Main program thread will now create all threads requested ...\n");

// Edit this pragma to include the `for` parameter
// maybe add default(none) to specifically define private, global, etc.
//#pragma omp parallel num_threads(thread_count)
    Hello_threads(thread_count);

    printf("All threads now done, main program proceeding to exit\n");

    return 0;
}

void Hello_threads(int thread_count)
{
    int i;
    int my_rank;
    # pragma omp parallel num_threads(thread_count) default(none) private(i, my_rank) shared(thread_count)
    {
        my_rank = omp_get_thread_num();
        for (i = 0; i < 4; i++) {
            printf("Hello from OMP thread %d of %d\n", my_rank, thread_count);
        }
    }
}
