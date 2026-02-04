#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	const char *emoji;
	const char *digits;
	int elen;
	int dlen;
} Emoji;

Emoji emojis[] = {
	{"📟",  "40404", 0, 0},
	{"🔢",  "1234",  0, 0},
	{"🎰",  "777",   0, 0},
	{"",  "109",   0, 0},
	{"💯",  "100",   0, 0},
	{"🏪",  "24",    0, 0},
	{"🧑🏻‍🏫", "22", 0, 0},
	{"🧑🏼‍🏫", "22", 0, 0},
	{"🧑🏽‍🏫", "22", 0, 0},
	{"🧑🏾‍🏫", "22", 0, 0},
	{"🧑🏿‍🏫", "22", 0, 0},
	{"👨🏻‍🏫", "22", 0, 0},
	{"👨🏼‍🏫", "22", 0, 0},
	{"👨🏽‍🏫", "22", 0, 0},
	{"👨🏾‍🏫", "22", 0, 0},
	{"👨🏿‍🏫", "22", 0, 0},
	{"👩🏻‍🏫", "22", 0, 0},
	{"👩🏼‍🏫", "22", 0, 0},
	{"👩🏽‍🏫", "22", 0, 0},
	{"👩🏾‍🏫", "22", 0, 0},
	{"👩🏿‍🏫", "22", 0, 0},
	{"🧑‍🏫", "22", 0, 0},
	{"👨‍🏫", "22", 0, 0},
	{"👩‍🏫", "22", 0, 0},
	{"🔞",  "18",    0, 0},
	{"📆",  "17",    0, 0},
	{"📅",  "17",    0, 0},
	{"🔟",  "10",    0, 0},
	{"9️⃣", "9", 0, 0},
	{"\x39\xe2\x83\xa3", "9", 0, 0},
	{"🎱",  "8",     0, 0},
	{"8️⃣", "8", 0, 0},
	{"\x38\xe2\x83\xa3", "8", 0, 0},
	{"7️⃣", "7", 0, 0},
	{"\x37\xe2\x83\xa3", "7", 0, 0},
	{"6️⃣", "6", 0, 0},
	{"\x36\xe2\x83\xa3", "6", 0, 0},
	{"5️⃣", "5", 0, 0},
	{"\x35\xe2\x83\xa3", "5", 0, 0},
	{"4️⃣", "4", 0, 0},
	{"\x34\xe2\x83\xa3", "4", 0, 0},
	{"🏎️", "3", 0, 0},
	{"🏎",  "3", 0, 0},
	{"🥉",  "3",     0, 0},
	{"3️⃣", "3", 0, 0},
	{"\x33\xe2\x83\xa3", "3", 0, 0},
	{"🥈",  "2",     0, 0},
	{"2️⃣", "2", 0, 0},
	{"\x32\xe2\x83\xa3", "2", 0, 0},
	{"🥇",  "1",     0, 0},
	{"🔂",  "1",     0, 0},
	{"1️⃣", "1", 0, 0},
	{"\x31\xe2\x83\xa3", "1", 0, 0},
	{"0️⃣", "0", 0, 0},
	{"\x30\xe2\x83\xa3", "0", 0, 0},
};
#define EMOJI_COUNT (sizeof(emojis)/sizeof(emojis[0]))

typedef struct {
	const char *emoji;
	const char *digits;
	int dlen;
} OutEmoji;

OutEmoji out_emojis[] = {
	{"📟",  "40404", 0},
	{"🔢",  "1234",  0},
	{"🎰",  "777",   0},
	{"",  "109",   0},
	{"💯",  "100",   0},
	{"🏪",  "24",    0},
	{"🧑‍🏫", "22", 0},
	{"🔞",  "18",    0},
	{"📆",  "17",    0},
	{"🔟",  "10",    0},
	{"9️⃣", "9", 0},
	{"🎱",  "8",     0},
	{"8️⃣", "8", 0},
	{"7️⃣", "7", 0},
	{"6️⃣", "6", 0},
	{"5️⃣", "5", 0},
	{"4️⃣", "4", 0},
	{"🏎️", "3", 0},
	{"3️⃣", "3", 0},
	{"🥈",  "2",     0},
	{"2️⃣", "2", 0},
	{"🔂",  "1",     0},
	{"1️⃣", "1", 0},
	{"0️⃣", "0", 0},
};
#define OUT_EMOJI_COUNT (sizeof(out_emojis)/sizeof(out_emojis[0]))


void parse_to_digits(const char *input, char *output) {
	int len = strlen(input);
	int i = 0, out = 0;

	while (i < len) {
		int matched = 0;
		for (int j = 0; j < (int)EMOJI_COUNT; j++) {
			if (i + emojis[j].elen <= len &&
				strncmp(input + i, emojis[j].emoji, emojis[j].elen) == 0) {
				memcpy(output + out, emojis[j].digits, emojis[j].dlen);
				out += emojis[j].dlen;
				i += emojis[j].elen;
				matched = 1;
				break;
			}
		}
		if (!matched) i++;
	}
	output[out] = '\0';
}

void bignum_add(const char *a, const char *b, char *result) {
	int alen = strlen(a), blen = strlen(b);
	int ai = alen - 1, bi = blen - 1;
	int carry = 0, ri = 0;
	char tmp[1024];

	while (ai >= 0 || bi >= 0 || carry) {
		int sum = carry;
		if (ai >= 0) sum += a[ai--] - '0';
		if (bi >= 0) sum += b[bi--] - '0';
		tmp[ri++] = (sum % 10) + '0';
		carry = sum / 10;
	}
	for (int i = 0; i < ri; i++)
		result[i] = tmp[ri - 1 - i];
	result[ri] = '\0';
}

int main(void) {
	for (int i = 0; i < (int)EMOJI_COUNT; i++) {
		emojis[i].elen = strlen(emojis[i].emoji);
		emojis[i].dlen = strlen(emojis[i].digits);
	}
	for (int i = 0; i < (int)OUT_EMOJI_COUNT; i++)
		out_emojis[i].dlen = strlen(out_emojis[i].digits);

	char a_str[100000], b_str[100000];
	if (!fgets(a_str, sizeof(a_str), stdin)) return 1;
	if (!fgets(b_str, sizeof(b_str), stdin)) return 1;
	a_str[strcspn(a_str, "\n")] = 0;
	b_str[strcspn(b_str, "\n")] = 0;

	char a_digits[600], b_digits[600];
	parse_to_digits(a_str, a_digits);
	parse_to_digits(b_str, b_digits);

	char *a = a_digits, *b = b_digits;
	while (*a == '0' && *(a + 1)) a++;
	while (*b == '0' && *(b + 1)) b++;

	char sum[1024];
	bignum_add(a, b, sum);

	int n = (int)strlen(sum);
	int dp[1024];
	int prev[1024];
	int choice[1024];
	for (int i = 0; i <= n; i++) {
		dp[i] = 1e9;
		prev[i] = -1;
		choice[i] = -1;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (int)OUT_EMOJI_COUNT; j++) {
			int dlen = out_emojis[j].dlen;
			if (dlen <= i && strncmp(sum + i - dlen, out_emojis[j].digits, dlen) == 0) {
				if (dp[i - dlen] + 1 < dp[i]) {
					dp[i] = dp[i - dlen] + 1;
					prev[i] = i - dlen;
					choice[i] = j;
				}
			}
		}
	}

	const char *out_seq[1024];
	int out_len = 0;
	for (int i = n; i > 0; i = prev[i]) {
		if (choice[i] < 0) break;
		out_seq[out_len++] = out_emojis[choice[i]].emoji;
	}
	for (int i = out_len - 1; i >= 0; i--)
		printf("%s", out_seq[i]);
	printf("\n");

	return 0;
}
