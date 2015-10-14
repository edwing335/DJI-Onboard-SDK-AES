# DJI-Onboard-SDK-AES

This is a simple demo for AES Encryption which is used in DJI Onboard SDK.

The key need to be converted into this form as the following shows, and then call `aes256_init`.

"390b75d49d51e9cea4..." ===> 0x39 0x0b 0x75 0xd4.....

At last, The AES Encryption in DJI Onboard SDK is optional. For more info please refer to [DJI Onboard SDK](https://github.com/dji-sdk/Onboard-SDK)