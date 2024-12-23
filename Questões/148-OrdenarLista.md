# 148. Lista de Ordenar - Média

<div align="center"><img src= "https://raw.githubusercontent.com/projeto-de-algoritmos-2024/D-C_LEETCODE_PROBLEMS/refs/heads/main/Images/148.png?raw=true"/></div>

---

## Vídeo Explicação

https://youtu.be/zolecrtyA78 

---

## Link Questão

https://leetcode.com/problems/sort-list/

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

struct ListNode* merge(struct ListNode* esquerda, struct ListNode* direita) {
    struct ListNode temp; 
    struct ListNode* cauda = &temp;
    temp.next = NULL;

    while (esquerda != NULL && direita != NULL) {
        if (esquerda->val  <= direita->val ){
            cauda->next = esquerda;
            esquerda = esquerda->next;
        } 
        else{
            cauda->next = direita;
            direita = direita->next;
        }
        cauda = cauda->next;
    }

    if (esquerda != NULL) cauda->next = esquerda;
    else cauda->next = direita;

    return temp.next;
}

struct ListNode* obterMeio(struct ListNode* cabeca) {
    struct ListNode* lento = cabeca;
    struct ListNode* rapido = cabeca->next;

    while (rapido != NULL && rapido->next != NULL) {
        lento = lento->next;
        rapido = rapido->next->next;
    }
    return lento;
}

struct ListNode* sortList(struct ListNode* cabeca) {
    if (cabeca == NULL || cabeca->next == NULL) return cabeca; 

    struct ListNode* meio = obterMeio(cabeca);
    struct ListNode* metadeDireita = meio->next;
    meio->next = NULL;

    struct ListNode* esquerdaOrdenada = sortList(cabeca);
    struct ListNode* direitaOrdenada = sortList(metadeDireita);
    return merge(esquerdaOrdenada, direitaOrdenada);
}
```
