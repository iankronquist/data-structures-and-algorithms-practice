from random import randint

def main():
    heap = seed_heap()
    print '[%s]' % ', '.join(map(str, heap)) 
    sort_heap(heap)
    print '[%s]' % ', '.join(map(str, heap)) 

def seed_heap():
    heap = []
    for x in range(0, 15):
        heap.append(randint(0, 100))
    return heap

def heapify(heap):
    for x in range((len(heap)-2)/2, -1, -1):
        sift_down(heap, x, len(heap)-1)

def sort_heap(heap):
    heapify(heap)
    for x in range(len(heap)-1, 0, -1):
        heap[x], heap[0] = heap[0], heap[x]
        sift_down(heap, 0, x-1)

def sift_down(heap, start, end):
    while((start*2)+1  <= end):
        child = (start*2)+1
        if((child+1 <= end) and (heap[child] < heap[child+1])):
            child+=1
        if(heap[start] < heap[child]):
            heap[start], heap[child] = heap[child], heap[start]
            start = child
        else: 
            return

main()
