## encoding algorithm to use

1. Base62 - URL safe, removes '+' and '/' charecters (simple)
2. Base58 - URL safe and also removes similar charecters like 'o' and '0', small l and capital i (better readability)

## Auto-Incrementing IDs 

1. Simple to use with a base encoding 
2. we keep a number with all long urls starting from 1 and map the encoded number to the url.
3. using Buffer.alloc(4) which means -  
    4-byte buffer can handle (0 to 4,294,967,295).