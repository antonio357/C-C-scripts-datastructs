#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

// https://en.wikibooks.org/wiki/C_Programming/inttypes.h
// 8 bits from int8_t == to 1 Byte

int main() {

    typedef struct {
        int8_t ip;
        int type; 
        int32_t addr_source;
        int32_t addr_dest;
        int8_t *payload; // = (int8_t *)malloc(n*sizeof(int8_t)); n <= 100
        int8_t payload_size; // = sizeof(Packet_name);
    } packet;

    packet *createDataPacket(int8_t ip_, int32_t addr_source_, int32_t addr_dest_, int8_t payload_size_) {
        packet p;
        packet *pp = &p;
        p.payload_size = payload_size_;
        p.payload = (int8_t*)malloc(p.payload_size*sizeof(int8_t));
        p.ip = ip_;
        p.addr_source = addr_source_;
        p.addr_dest = addr_dest_;
        return pp;
    };

    packet *createACKPacket(int ip_, int32_t addr_source_, int32_t addr_dest_) {
        packet p;
        packet *pp = &p;
        p.payload = NULL;
        p.payload_size = 0;
        return pp;
    }

    void writeData(packet *p_, int8_t bytes_array[], int8_t array_len) {
        int8_t i;
        for (i = 0; i < p_->payload_size; i++) {
            p_->payload[i] = bytes_array[i];
        }
        if (array_len < p_->payload_size) {
            for (i = i; i < p_->payload_size; i++) {
                p_->payload[i] = 0;
            }
        }
        return;
    }

    packet *clonePacket(const packet *p_) {
        packet p;
        p.ip = p_->ip;
        p.type = p_->type;
        p.payload_size = p_->payload_size;
        p.addr_source = p_->addr_source;
        p.addr_dest = p_->addr_dest;
        p.payload = (int8_t*)malloc(p.payload_size*sizeof(int8_t));
        for (int8_t i = 0; i < p_->payload_size; i++) {
            p.payload[i] = p_->payload[i];
        }
        packet *pp = &p;
        return pp;
    }

    void printPacketInformation(packet *p_) {
        if (p_->payload == NULL) {
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
        return;
    }

    return 0;
}