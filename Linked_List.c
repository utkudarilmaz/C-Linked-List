#include "stdio.h"
#include <stdlib.h>

typedef struct node{ // Node isminde tanımlanan düğüm yapısı
    int data;
    struct node *next;
}Node;

void add_Node(Node**,Node*);    // Dugum ekleme fonksiyonu
void print_List(Node*);         // Dugumleri yazdırma fonksiyonu
void del_Node(Node**,Node*);    // Dugum silme fonksiyonu
void search_Node(Node*);        // Bağlı listede arama yapan fonksiyon

int main(){
    Node* head=NULL; // İlk düğümü gösteren pointer
    int secim_Menu,secim,sonsuz=1,i=0;
    while(sonsuz){ // Menunun her ıslemden sonra gelmesini sağlayan döngü
        printf("\n1: Tek eleman ekleme\n2: Birden fazla eleman ekleme\n3: Eleman silme\n4: Elemanlari yazdirma\n5: Eleman arama\n6: Cikis\nSecim: ");
                scanf("%d",&secim_Menu );
        switch (secim_Menu) { // Menu
            case 1: // Bir dugum ekleme seçeneği
                printf("\n");
                add_Node(&head,head);
                break;
            case 2: // Birden fazla dugum ekleme seçeneği
                printf("\nKac eleman girmek istiyorsunuz?\nSecim :");
                scanf("%d",&secim);
                while(i<secim){
                    add_Node(&head,head);
                    i++;
                }
                break;
            case 3: // Dugum silme seceneği
                del_Node(&head,head);
                break;
            case 4: // Baglı listeyi yazdıracak fonksiyon
                print_List(head);
                printf("\n");
                break;
            case 5: // Bağlı listede arama yapan fonksiyon
                search_Node(head);
                break;
            case 6: // Çıkış
                sonsuz=0;
                break;
        }
        printf("----------------------------------------------------------------------------------------------\n");
    }

    return 0;
}

void add_Node(Node** head_null,Node* head){ // Dugum ekleme fonksiyonu
    if(head==NULL){ // Baglı listenin ilk elemanının eklendiği kısım
        Node* new_Node=(Node*)malloc(sizeof(Node));
        *head_null=new_Node;
        printf("Deger: ");
        scanf("%d",&(new_Node->data));
        new_Node->next=NULL;
        return;
    }
    else{ // İlk elemandan sonraki herhangi bir yere düğüm eklenilen kısım
        Node* temp;
        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                temp=temp->next;
            }else break;
        }
        Node* new_Node=(Node*)malloc(sizeof(Node));
        printf("Deger: ");
        scanf("%d",&(new_Node->data));
        new_Node->next=NULL;
        temp->next=new_Node;
        return;
    }
}

void del_Node(Node** head_new,Node* head){ // Girilen sıradaki düğümü silecek fonksiyon
    int target;
    printf("\nKacinci elemani silmek istiyorsunuz?\nSecim :");
    scanf("%d",&target);
    Node* temp=head;
    if(target==1){ // Eğer girilen değer ilk elemana tekabül ediyorsa bu kısım calısır
        *head_new=temp->next;
        free(temp);
        return;
    }
    int i=1;
    while(i<target-1){
        temp=temp->next;
        i++;
    }
    Node* temp_ex;
    if(temp->next->next==NULL){ // Eğer girilen değer son elemana tekabül ediyorsa burası çalışır
        temp_ex=temp->next;
        temp->next=NULL;
        free(temp_ex);
        return;
    }
    temp_ex=temp->next;
    temp->next=temp->next->next;
    free(temp_ex);
    printf("%d. Terim silindi\n",target);
}

void search_Node(Node* head){ // Bağlı listede arama yapan fonksiyon
    Node* temp=head;
    int target,count=1;
    printf("\nAranacak Deger: ");
    scanf("%d",&target);
    while(temp!=NULL){ // Dugum olduğu sürece arama yapılmasını sağlayan döngü
        if(temp->data==target){ // Aranan değerin bulunma durumu
            printf("Bulundu!\nAranan deger listenin %d. elemanı\n",count);
            return;
        }
        temp=temp->next;
        count++;
    }
    printf("Aranan deger listede bulunamadı!\n");
}

void print_List(Node* head){ // Bağlı listeyi yazdıran fonksiyon
    Node* temp=head;
    do{
        printf("%d\n",temp->data);
        temp=temp->next;
    }while(temp!=NULL);
}
