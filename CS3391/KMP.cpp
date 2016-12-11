//KMP

void kmp(char str[], int next[], int n)
{
	int i = 0, j = -1;
	next[0] = -1;
	while (i<n)
		if (j == -1 || str[i] == str[j]) next[++i] = ++j;
		else j = next[j];
}
//return the position of where matched
int go_match(char str[], int key[], int next[], int nstr, int nk)
{
	//nstr=strlen(str),nk=strlen(key) || to the expected length
	int i = 0, j = 0;
	while (i < nstr && j < nk) {
		if (j == -1 || str[i] == key[j]) { i++; j++; }
		else j = next[j];
	}
	if (j == nk) 
		return i - nk + 1; //matched
	else 
		return -1; //not matched
}
