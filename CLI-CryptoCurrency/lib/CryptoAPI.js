const axios = require('axios')
const colors = require('colors')

class CryptoAPI {
    constructor(apiKey){
        this.apiKey = apiKey;
        this.baseURL = 'https://api.nomics.com/v1/currencies/ticker'
    }

    async getPriceData(coinOption, curOption){
        try{
            // Formatter For Currency

            const formatter = new Intl.NumberFormat('en-US', {
                style: 'currency',
                currency: curOption
            });

            const res = await axios.get(`${this.baseURL}?key=${this.apiKey}&ids=${coinOption}&convert=${curOption}`);

            let output = '';

            res.data.forEach(coin => {
                output += `\nCoin: ${coin.symbol.yellow} (${coin.name}) \n| Price: ${formatter.format(coin.price).green} \n|  Rank: ${coin.rank.blue}`;
            });
            
            return output ;

        } catch (err) {
            handleAPIError(err);
        }
    }
}

function handleAPIError(err) {
    if (err.response.status === 401){
        throw new Error('Your API key is invalid - Go to https://nomics.com')
    } else if (err.response.status === 404){
        throw new Error('Your API key is not responding')
    } else {
        throw new Error ('Something went wrong')
    }
}

module.exports = CryptoAPI ;