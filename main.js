/**
 * Responds to any HTTP request.
 *
 * @param {!express:Request} req HTTP request context.
 * @param {!express:Response} res HTTP response context.
 */
const scraperjs = require('scraperjs');
exports.main = (req, res) => {
    //let message = req.query.message || req.body.message || 'Hello World!';
    scraperjs.StaticScraper.create('https://atcoder.jp/users/hotman78/history')
        .scrape(($) => {
            var ret={};
            ret['a']=$('tbody').text();
            for(var e of $('tbody').children()){
                var tmp=e.children();
                var time=tmp[0].attr('data-order');
                var name=tmp[1].children()[0].text();
                var rank=tmp[2].children()[0].text();
                ret[time+name]={'time':time,'name':name,'rank':rank};
            }
            return JSON.stringify(ret);
        }).then((title) => {
            res.status(200).send(title);
        }).catch((error) => {
            res.status(500).send(error);
        });
};
