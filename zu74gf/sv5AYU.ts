import * as https from 'https';

const scrapeWebsite = (url: string): Promise<any> => {
    return new Promise((resolve, reject) => {
        https.get(url, (res) => {
            let data = '';

            res.on('data', (chunk) => {
                data += chunk;
            });

            res.on('end', () => {
                const getTitle = /<title>(.*?)<\/title>/i.exec(data);
                const getMetaDescription = /<meta name="description" content="(.*?)"/i.exec(data);
                const getH1s = data.match(/<h1.*?>(.*?)<\/h1>/gi) || [];
                const getH2s = data.match(/<h2.*?>(.*?)<\/h2>/gi) || [];
                const getH3s = data.match(/<h3.*?>(.*?)<\/h3>/gi) || [];
                const getImgs = (data.match(/<img[^>]+src="([^"]+)"/gi) || []).map(img => /src="([^"]+)"/i.exec(img)[1]);

                resolve({
                    title: getTitle ? getTitle[1] : '',
                    metaDescription: getMetaDescription ? getMetaDescription[1] : '',
                    h1: getH1s,
                    h2: getH2s,
                    h3: getH3s,
                    images: getImgs
                });
            });
        }).on('error', (err) => {
            reject(`Failed to scrape ${url}. Error: ${err.message}`);
        });
    });
};

// Sample usage:
const url = 'https://example.com'; // change this to any website you want to scrape
scrapeWebsite(url).then(result => console.log(result)).catch(error => console.error(error));
