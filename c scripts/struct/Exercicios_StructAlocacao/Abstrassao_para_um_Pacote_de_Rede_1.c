#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

// https://en.wikibooks.org/wiki/C_Programming/inttypes.h
// 8 bits from int8_t == to 1 Byte

#define DATA 1
#define ACK 0

    typedef struct {
        int8_t ip;
        int type; 
        int32_t addr_source;
        int32_t addr_dest;
        int8_t *payload; // = (int8_t *)malloc(n*sizeof(int8_t)); n <= 100
        int8_t payload_size; // = sizeof(Packet_name);
    } packet;

packet* createDataPacket(int8_t ip_, int32_t addr_source_, int32_t addr_dest_, int8_t payload_size_) {
        packet *p = (packet*)malloc(sizeof(packet));
        //if (p == NULL) {printf("Não foi possível alocar memória para o packet\n"); return NULL;}
        p->payload = (int8_t*)malloc(p->payload_size*sizeof(int8_t));
        //if (p->payload == NULL) {printf("Não foi possível alocar memória para o payload do packet\n"); return NULL;}
        p->payload_size = payload_size_;
        p->ip = ip_;
        p->addr_source = addr_source_;
        p->addr_dest = addr_dest_;
        p->type = DATA;
        return p;
    };

    packet* createACKPacket(int ip_, int32_t addr_source_, int32_t addr_dest_) {
        packet *p = (packet*)malloc(sizeof(packet));
        if (p == NULL) {printf("Não foi possível alocar memória para o packet\n"); return NULL;}
        p->ip = ip_;
        p->type = ACK;
        p->addr_source = addr_source_;
        p->addr_dest = addr_dest_;
        p->payload = NULL;
        p->payload_size = 0;
        return p;
    }

    void writeData(packet *p_, int8_t bytes_array[], int8_t array_len) {
        int8_t i;
        for (i = 0; i < array_len; i++) {
            if (i >= p_->payload_size) break;
            p_->payload[i] = bytes_array[i];
            //printf("i_antes = %d\n", i);
        }
        if (array_len < p_->payload_size) {
            for (i = i; i < p_->payload_size; i++) {
                p_->payload[i] = 0;
                //printf("i_depois = %d\n", i);
            }
        }
        return;
    }

    packet* clonePacket(const packet *p_) {
        packet *p = (packet*)malloc(sizeof(packet));
        p->ip = p_->ip;
        p->type = p_->type;
        p->payload_size = p_->payload_size;
        p->addr_source = p_->addr_source;
        p->addr_dest = p_->addr_dest;
        //p.payload = p_->payload;
        p->payload = (int8_t*)malloc(p->payload_size*sizeof(int8_t));
        for (int8_t i = 0; i < p_->payload_size; i++) {
            p->payload[i] = p_->payload[i];
        }
        return p;
    }

    void printPacketInformation(packet *p_) {
        if (p_->type == ACK) {
            printf("Packet type: ACK\n");
            printf("ID: %d\n", p_->ip);
            printf("Source Address: %d\n", p_->addr_source);
            printf("Destination Address: %d\n", p_->addr_dest);
        }
        else {
            printf("Packet type: DATA\n");
            printf("ID: %d\n", p_->ip);
            printf("Source Address: %d\n", p_->addr_source);
            printf("Destination Address: %d\n", p_->addr_dest);
            printf("Payload Size: %d\n", p_->payload_size);
            printf("Payload: ");
            for (int8_t i = 0; i < p_->payload_size; i ++) {
                if (i < (p_->payload_size) - 1) printf("%d ", p_->payload[i]);
                else if (i == (p_->payload_size) - 1) printf("%d\n", p_->payload[i]);
            }
        }
        return;
    }
    
    void deletePacket(packet *p_) {
        free(p_->payload);
        free(p_);
        //printf("%i", (*p_ + 1000));
        return;
    }

int main() {
    packet *t = createDataPacket(32,0,1,15);
    int8_t p[10] = {0,1,2,3,4,5,6,7,8,9};
    writeData(t,p,10);
    printPacketInformation(t);
    return 0;
}