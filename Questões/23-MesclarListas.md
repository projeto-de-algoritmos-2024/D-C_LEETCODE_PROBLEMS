# 148. Mesclar listas Classificadas K- Difícil

<div align="center"><img src= "https://raw.githubusercontent.com/projeto-de-algoritmos-2024/D-C_LEETCODE_PROBLEMS/refs/heads/main/Images/23.png?raw=true"/></div>

---

## Vídeo Explicação

https://youtu.be/wVxXdo6kUoo

---

## Link Questão

https://leetcode.com/problems/merge-k-sorted-lists/

---

## **Código**

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void swap(int *vetor, int A, int B) {
    int temp = vetor[A];
    vetor[A] = vetor[B];
    vetor[B] = temp;
}

void merge(int *numeros, int l, int meio, int r) {

    int tam = r+1 - l ;       // Calcula o tamanho

    // alocar espaço auxiliar
    int *aux = malloc ( tam * sizeof (int) );

    int i = l ;                 // inicio do sub - vetor esquerdo
    int j = meio +1;            // inicio do sub - vetor direito
    int k =0;                   // inicio do vetor auxiliar

    // ordenar em aux [k]
    while (k < tam ) {                              // condição de parada do aux

        if(i > meio )                               // ordenou o primeiro sub - vetor
            aux [k++] = numeros[j++];               // consome o segundo sub - vetor

        else if (j > r )                            // ordenou o segundo sub - vetor
            aux [k++] = numeros[i++];               // consome o primeiro sub - vetor

        else if ( numeros[ i ] < numeros[ j ])      // testar sub - vetores
            aux [k++] = numeros[ i ++];             // ordene no aux

        else aux [k++] = numeros[j++];              // ordene no aux
    }

    k = 0;                                         // indice do aux
    for( i = l ; i <= r ; i ++)                     // indice do v
        numeros[i] = aux [k++];                   // copiar o aux[k] para v[i]

    // liberar memória
    free ( aux ) ;
}

void mergeSort (int *numeros , int l , int r ) {
    if ( l >= r ) return ;                        // ver se atingiu o fim

    int meio = ( r+l) /2;

    mergeSort (numeros , l , meio ) ;           //F(n/2)
    mergeSort (numeros , meio + 1 , r ) ;       //F(n/2)
    merge (numeros , l , meio , r ) ;             //n
}

struct ListNode* arrayToListNode(int* array, int size) {
    if (size == 0) return NULL;  

    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    head->val = array[0];
    head->next = NULL;

    struct ListNode* current = head;

    for (int i = 1; i < size; i++) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = array[i];
        newNode->next = NULL;
        current->next = newNode;  
        current = newNode;  
    }

    return head;  
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

    if (listsSize == 0) return NULL;

    int tamanho = 0;
    for(int i = 0; i < listsSize; i++){
        struct ListNode* current = lists[i];
        while (current != NULL) {
            tamanho++;
            current = current->next;
        }
    }

    int* listaTotal = (int*)malloc(tamanho * sizeof(int));

    int index = 0;

    for (int i = 0; i < listsSize; i++) {
        struct ListNode* current = lists[i];
        while (current != NULL) {
            listaTotal[index++] = current->val;
            current = current->next;
        }
    }

    mergeSort(listaTotal, 0, tamanho-1);
    return arrayToListNode(listaTotal, tamanho);
}
```
