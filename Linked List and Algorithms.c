// Written by Utku Darilmaz
// Contact adress: utkudarilmaz@gmail.com

#include "stdio.h"

/* Düğüm yapısı */
typedef struct node{
    int data;
    struct node* next;
}Node;

typedef Node* Nodeptr*;

/* Liste yapısı */
typedef struct list{
    Nodeptr head;
    Nodeptr last;
}List;

typedef List* Listptr;

/* Listenin başına ekleme yapan fonksiyon */
void addListHead(Listptr l,Nodeptr new){
    if(l->last==NULL){
        l->last=new;
    }
    new->next=l->head;
    l->head=new;
}
/*
1- Eğer listenin sonu NULL'a eşitse listenin sonuna yeni düğümün adresini ata.
2- Yeni düğümün next pointerına listenin başını ata.
3- Listenin başına yeni düğümün adresini ata.
*/

/* Listenin sonuna ekleme yapan fonksiyon */
void addListLast(Listptr l,Nodeptr new){
    if(l->head==NULL){
        l->head=new;
    }
    else{
        l->last->next=new;
    }
    l->last=new;
}
/*
1- Eğer listenin başı NULL'sa listenin başına yeni düğümün adresini ata.
2- Değilse listenin sonunun next pointerına yeni düğümün adresini ata.
3- Listenin sonuna yeni düğümün adresini ata.
*/

/* Listenin ortasına ekleme yapan fonksiyon */
void addList(Nodeptr pre,Nodeptr new){
    new->next=pre->next;
    pre->next=new;
}
/*
1- Yeni düğümün next pointerına önceki düğümün next pointerındaki adresi ata.
2- Onceki düğümün next pointerına yeni düğümün adresini ata.
*/

/* Listenin başından eleman silen fonksiyon */
void delNodeHead(Listptr l){
    l->head=l->head->next;
    if(l->head==NULL){
        l->last=NULL;
    }
}
/*
1- Listenin başına listenin başının gösterdiği düğümün next pointerındaki adresi ata.
2- Eğer listenin başı NULL'a eşitse listenin sonuna NULL ata.
*/

/* Listenin sonundan eleman silen fonksiyon */
void delNodeLast(Listptr l){
    if(l->head->next==NULL){
        free(l->head);
        l->head==NULL;
        l->last==NULL;
        return;
    }
    Nodeptr temp;
    temp=l->head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(l->last);
    l->last=temp;
    temp->next=NULL;
}
/*
1- Eğer listenin başının gösterdiği düğümün next pointerı NULL'a eşitse listenin başını bellekten sil
    listenin başına ve sonuna NULL ata ve fonksiyondan çık.
2- Düğümü işaret eden bir temp adında pointer oluştur.
3- temp pointerına listenin başının gösterdiği adresi ata.
4- temp'in next pointerının gösterdiği düğümün next pointerının gösterdiği düğüm NULL'dan farklı olduğu
    müddet temp'e temp'in next pointerının gösterdiği adresi ata.
5- Listenin sonunu bellekten sil.
6- Listenin sonuna temp'in gösterdiği adresi ata.
7- temp'in next pointerına NULL değerini ata.
*/

/* Listenin ortasından eleman silen fonksiyon */
void delNode(Listptr l,Nodeptr del){
    Nodeptr temp,preNode;
    temp=l->head;
    preNode=NULL;
    while (temp!=del){
        preNode=temp;
        temp=temp->next;
    }
    preNode->next=del->next;
}
/*
1- Düğümü gösteren temp ve preNode adında iki pointer oluştur.
2- temp pointerına listenin başının adresini ata.
3- preNode pointerına NULL ata.
4- temp pointerı silinecek düğüme eşit olmadığı sürece, preNode pointerına temp pointerının gösterdiği adresi
    ata ve temp pointerına da temp'in next pointerının gösterdiği adresi ata.
5- preNode'un next pointerına silinecek düğümün next pointerının gösterdiği adresi ata.
*/

/* Listede eleman arayan fonksiyon */
void search(Listptr l,int value){
    Nodeptr temp;
    temp=l->head;
    while(temp!=NULL){
        if(temp->data==value) return temp;
        temp=temp->next;
    }
    return NULL;
}
/*
1- Düğümü işaret eden temp adında bir pointer oluştur.
2- temp'e listenin başının gösterdiği düğümün adresini ata.
3- temp pointerı NULL'dan farklı olduğu sürece; eğer temp'in gösterdiği düğümün verisi aranan veriye eşitse temp
    pointerının gösterdiği adresi döndür, temp'e temp'in next pointerının gösterdiği adresi ata.
4- NULL döndür.
