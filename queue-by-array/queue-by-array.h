#ifndef QUEUE_BY_ARRAY_H
#define QUEUE_BY_ARRAY_H

#ifndef DATA_TYPE 
#ifndef SIZE 
#define DATA_TYPE int
#define SIZE 10
#endif 
#endif 

DATA_TYPE queue[SIZE];

struct queue_by_array {
    void (*initialize)(DATA_TYPE* queue);
    void (*insert)(DATA_TYPE* queue, DATA_TYPE value);
    DATA_TYPE (*deleteElement)(DATA_TYPE* queue);
    DATA_TYPE (*peek)(DATA_TYPE* queue);
    void (*display)(DATA_TYPE* queue);
    void (*reset)(DATA_TYPE* queue);
};

extern const struct queue_by_array QUEUE_BY_ARRAY;

#endif