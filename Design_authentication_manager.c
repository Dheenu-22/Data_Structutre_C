#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[6];
    int exp;
} Token;

typedef struct {
    int ttl;
    Token t[2000];
    int n;
} AuthenticationManager;

AuthenticationManager* authenticationManagerCreate(int timeToLive) {
    AuthenticationManager* a = malloc(sizeof(AuthenticationManager));
    a->ttl = timeToLive;
    a->n = 0;
    return a;
}

void authenticationManagerGenerate(AuthenticationManager* a, char* tokenId, int time) {
    strcpy(a->t[a->n].id, tokenId);
    a->t[a->n].exp = time + a->ttl;
    a->n++;
}

void authenticationManagerRenew(AuthenticationManager* a, char* tokenId, int time) {
    for(int i = 0; i < a->n; i++) {
        if(strcmp(a->t[i].id, tokenId) == 0 && a->t[i].exp > time) {
            a->t[i].exp = time + a->ttl;
            return;
        }
    }
}

int authenticationManagerCountUnexpiredTokens(AuthenticationManager* a, int time) {
    int c = 0;
    for(int i = 0; i < a->n; i++) {
        if(a->t[i].exp > time) c++;
    }
    return c;
}

void authenticationManagerFree(AuthenticationManager* a) {
    free(a);
}
