#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
	int elems[MAX];
	int rear;
	int front;
} Queue;

void initialize(Queue *);
void enqueueSorted(Queue *, int); //Implement your code in this function !!
void dequeue(Queue *);
void read(Queue);
int size(Queue);

int main() {
    int n;
    printf("Elems in queue: ");
    scanf("%d", &n);

	Queue Q;
	initialize(&Q);

    int input;
	//int test[input] = {31,24,81,12,22};

    for(int i = 0; i < n ; i++) {
        scanf("%d", &input);
        enqueueSorted(&Q, input);
    }

   read(Q);
}

void initialize(Queue *Q) {
	Q->front = 0;
	Q->rear = MAX - 1;
}

int size(Queue Q) {
	return (Q.rear - Q.front + MAX + 1) % MAX;
}

bool isEmpty(Queue Q) {
	return (Q.rear + 1) % MAX == Q.front;
}

bool isFull(Queue Q) {
	return (Q.rear + 2) % MAX == Q.front;
}

void enqueue(Queue *Q, int x) {
	if(!isFull(*Q)) {
		Q->rear = (Q->rear + 1) % MAX;
		Q->elems[Q->rear] = x;
	}
}

void enqueueSorted(Queue *Q, int x) { 
    //implement code here...
	Queue tempQ;
	initialize(&tempQ);
	bool added = false;
	if(!isFull(*Q)){
		if(isEmpty(*Q) || Q->elems[Q->rear] < x){
			enqueue(Q, x);
		} else {
			while(!isEmpty(*Q) && !isFull(*Q)){
				if(Q->elems[Q->front] > x){ 		// if x is lesser than front of Q   e.g 3 > 1
					enqueue(&tempQ, x);				// insert x into tempQ	tempQ = 1,n,n,n,n
					while(!isEmpty(*Q)){			// transfer greater values to tempQ tempQ = 1,3,5,6,n,n
						enqueue(&tempQ, Q->elems[Q->front]);
						dequeue(Q);
					}
					break;							// break loop
				} else {							// else 
					enqueue(&tempQ, Q->elems[Q->front]);
					dequeue(Q);
				}
			}
			for(; !isEmpty(tempQ) ;){
				enqueue(Q, tempQ.elems[tempQ.front]);
				dequeue(&tempQ);
			}
		}
	}
}

void dequeue(Queue *Q) {
	if(!isEmpty(*Q)) {
		Q->front = (Q->front + 1) % MAX;
	}
}

void read(Queue Q) {
	if(!isEmpty(Q)) {
		int i;
		int n = size(Q);
        printf("Sorted Queue: ");
		for(i = 0; i < n; i++) {
			int temp = Q.elems[Q.front];
			Q.front = (Q.front + 1) % MAX;
			printf("%d ", temp);
		}
	}
}
