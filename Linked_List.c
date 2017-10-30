#include "stdio.h"
#include <stdlib.h>
#include <time.h>

typedef struct node{ // Node isminde tanimlanan dugum yapisi
    double data;
    struct node *next;
}Node;

void add_Node(Node**,Node*);    // Dugum ekleme fonksiyonu
void print_List(Node*);         // Dugumleri yazdirma fonksiyonu
void del_Node(Node**,Node*);    // Dugum silme fonksiyonu
void search_Node(Node*);        // Bagli listede arama yapan fonksiyon
void rand_five(Node**,Node*);   // Listenin başına 5 adet rastegele düğüm ekleyen fonksiyon

int main(){
    srand (time(NULL));
    Node* head=NULL; // Ilk dugumu gosteren pointer
    int secim_Menu,secim,sonsuz=1,i=0;
    for(;i<5;i++){
        rand_five(&head,head);
    }
    while(sonsuz){ // Menunun her islemden sonra gelmesini saglayan dongu
        printf("\n1: Tek eleman ekleme\n2: Eleman silme\n3: Elemanlari yazdirma\n4: Eleman arama\n0: Cikis\nSecim: ");
        scanf("%d",&secim_Menu);
        switch (secim_Menu) { // Menu
            case 1: // Bir dugum ekleme secenegi
                printf("\n");
                add_Node(&head,head);
                print_List(head);
                printf("\n");
                break;
            case 2: // Dugum silme secenegi
                del_Node(&head,head);
                print_List(head);
                printf("\n");
                break;
            case 3: // Bagli listeyi yazdiracak fonksiyon
                print_List(head);
                printf("\n");
                break;
            case 4: // Bagli listede arama yapan fonksiyon
                search_Node(head);
                break;
            case 0: // Cikis
                sonsuz=0;
                break;
        }
        printf("----------------------------------------------------------------------------------------------\n");
    }
    return 0;
}

void rand_five(Node** head_null,Node* head){ // Dugume otomatik 5 dugum ekleyen ve her dugumun data degiskenine random deger ekleyen fonksiyon
    if(head==NULL){ // Listeye ilk dugumu ekleyen kisim
        Node* new_Node=(Node*)malloc(sizeof(Node));
  		*head_null=new_Node;
  		new_Node->data=rand()%100;
  		new_Node->next=NULL;
  		return;
  	}
    else{
        Node* temp;
        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                temp=temp->next;
            }
            else break;
        }
        Node* new_Node=(Node*)malloc(sizeof(Node));
        new_Node->data=rand()%100;
        new_Node->next=NULL;
        temp->next=new_Node;
        return;
    }
}

void add_Node(Node** head_new,Node* head){ // Dugum ekleme fonksiyonu
    int secim,sayac=0;
    printf("Eklenilecek yer: ");
    scanf("%d",&secim);
    Node* sayim=head;
    while(sayim!=NULL){
        sayac++;
        if(sayim->next!=NULL){
            sayim=sayim->next;
        }
        else break;
    }
    if(secim==1){ // Bagli listenin basina ekleme
        Node* new_Node=(Node*)malloc(sizeof(Node));
        Node* temp=head;
        *head_new=new_Node;
        printf("Yeni elemanin degeri: ");
        scanf("%lf",&(new_Node->data));
        new_Node->next=temp;
        return;
    }
    if(secim==sayac){ // Sona ekleme
        Node* temp;
        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                temp=temp->next;
            }
            else break;
        }
        Node* new_Node=(Node*)malloc(sizeof(Node));
        printf("Yeni elemanin degeri: ");
        scanf("%lf",&(new_Node->data));
        new_Node->next=NULL;
        temp->next=new_Node;
        return;
    }
    else{ // Araya ekleme
        Node* new_Node=(Node*)malloc(sizeof(Node));
        Node* temp=head;
        int i=1;
        while(i<secim-1){
      	     temp=temp->next;
          	 i++;
  		}
        printf("Yeni eleman�n degeri: ");
        scanf("%lf",&(new_Node->data));
        new_Node->next=temp->next;
        temp->next=new_Node;
      	return;
  	}
}

void del_Node(Node** head_new,Node* head){ // Girilen siradaki dugumu silecek fonksiyon
    int target;
    printf("\nKacinci elemani silmek istiyorsunuz?\nSecim :");
    scanf("%d",&target);
    Node* temp=head;
    if(target==1){ // Eger girilen deger ilk elemana tekabul ediyorsa bu kisim calisir
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
    if(temp->next->next==NULL){ // Eger girilen deger son elemana tekabul ediyorsa burasi calisir
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

void search_Node(Node* head){ // Bagli listede arama yapan fonksiyon
    Node* temp=head;
    float target;
  	int count=1;
    printf("\nAranacak Deger: ");
    scanf("%f",&target);
    while(temp!=NULL){ // Dugum oldugu sürece arama yapilmasini saglayan dongu
        if(temp->data==target){ // Aranan degerin bulunma durumu
            printf("Bulundu!\nAranan deger listenin %d. elemani\n",count);
            return;
        }
        temp=temp->next;
        count++;
    }
    printf("Aranan deger listede bulunamad�!\n");
}

void print_List(Node* head){ // Bagli listeyi yazdiran fonksiyon
    Node* temp=head;
    do{
        printf("%f\n",temp->data);
        temp=temp->next;
    }while(temp!=NULL);
}
