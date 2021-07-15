#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
/* example

bool f(const void* x){
    return (*(int*)x)==1;
}

int main(){
    int a=1,b=2,c=3,d=4;
    vector* v=vector_init(3,(void*)&a,sizeof(int));
    vector_push(v,(void*)&b);
    vector_push(v,(void*)&c);
    vector_push(v,(void*)&d);
    for(int i=0;i<vector_size(v);++i){
        printf("%d\n",*(int *)vector_get(v,i));
    }
    vector_remove_if(v,f);
    puts("");
    for(int i=0;i<vector_size(v);++i){
        printf("%d\n",*(int *)vector_get(v,i));
    }
}

*/

typedef struct vector
{
    int n, max, data_size;
    void *data;
} vector;

vector *vector_init(int n, void *x, int data_size)
{
    vector *ret = (vector *)malloc(sizeof(vector));
    ret->n = n;
    ret->max = n;
    ret->data_size = data_size;
    ret->data = malloc(n * data_size);
    for (int i = 0; i < n; i++)
    {
        memcpy(ret->data + ret->data_size * i, x, ret->data_size);
    }
    return ret;
}

void vector_push(vector *v, void *x)
{
    if (v->n == v->max)
    {
        v->max *= 2;
        assert(realloc(v->data, v->max * sizeof(int)) != NULL);
    }
    memcpy(v->data + v->data_size * v->n, x, v->data_size);
    v->n++;
}
void vector_set(vector *v, int idx, void *x)
{
    memcpy(v->data + v->data_size * idx, x, v->data_size);
}
void *vector_get(vector *v, int idx)
{
    return (v->data + v->data_size * idx);
}
int vector_size(vector *v)
{
    return v->n;
}

void *vector_remove_if(vector *v, bool (*pred)(const void *))
{
    void *result = v->data;
    int del_count = 0;
    for (int i = 0; i < v->n; ++i)
    {
        void *first = vector_get(v, i);
        if (!pred(first))
        {
            if (result != first)
            {
                memcpy(result, first, v->data_size);
            }
            result += v->data_size;
            ++del_count;
        }
    }
    v->n -= del_count;
    return result;
}