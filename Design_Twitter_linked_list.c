#define MAX_USERS 501
#define MAX_FEED 10
typedef struct Tweet {
    int tweetId;
    int time;
    struct Tweet *next;
} Tweet;
typedef struct {
    int follows[MAX_USERS];
    Tweet *tweets;
} User;
typedef struct {
    User users[MAX_USERS];
    int time;
} Twitter;
Twitter* twitterCreate() {
    Twitter *obj = (Twitter *)calloc(1, sizeof(Twitter));
    obj->time = 0;
    return obj;
}
void twitterPostTweet(Twitter* obj, int userId, int tweetId) {
    Tweet *t = (Tweet *)malloc(sizeof(Tweet));
    t->tweetId = tweetId;
    t->time = obj->time++;
    t->next = obj->users[userId].tweets;
    obj->users[userId].tweets = t;
}
void twitterFollow(Twitter* obj, int followerId, int followeeId) {
    if (followerId == followeeId) return;
    obj->users[followerId].follows[followeeId] = 1;
}
void twitterUnfollow(Twitter* obj, int followerId, int followeeId) {
    if (followerId == followeeId) return;
    obj->users[followerId].follows[followeeId] = 0;
}
int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize) {
    Tweet *candidates[MAX_USERS];
    int count = 0;
    candidates[count++] = obj->users[userId].tweets;
    for (int i = 0; i < MAX_USERS; i++) {
        if (obj->users[userId].follows[i]) {
            candidates[count++] = obj->users[i].tweets;
        }
    }
    int *result = (int *)malloc(sizeof(int) * MAX_FEED);
    *retSize = 0;
    for (int k = 0; k < MAX_FEED; k++) {
        int maxIdx = -1;
        int maxTime = -1;
        for (int i = 0; i < count; i++) {
            if (candidates[i] && candidates[i]->time > maxTime) {
                maxTime = candidates[i]->time;
                maxIdx = i;
            }
        }
        if (maxIdx == -1)
            break;

        result[(*retSize)++] = candidates[maxIdx]->tweetId;
        candidates[maxIdx] = candidates[maxIdx]->next;
    }
    return result;
}
void twitterFree(Twitter* obj) {
    for (int i = 0; i < MAX_USERS; i++) {
        Tweet *t = obj->users[i].tweets;
        while (t) {
            Tweet *tmp = t;
            t = t->next;
            free(tmp);
        }
    }
    free(obj);
}
