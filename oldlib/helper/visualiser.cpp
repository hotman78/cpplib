struct vis{
    FILE* fp;
    vis(string file_name){
        fp=fopen((file_name+".html").c_str(),"w+");
        fprintf(fp,R"(
            <html><head><script>
                onload=function draw(){
                    var cnt=0;
                    var ct=document.getElementById('c').getContext('2d');
                    setInterval(function(){
                        ct.beginPath();
                        ct.moveTo(0,0);
                        ct.lineTo(1000,1000);
                        ct.closePath();
                        ct.stroke();
                        cnt++;
                    },100);
                };
            </script></head><body><canvas id='c',width='1000',height='1000'></canvas></body></html>)"
        );
    }
    ~vis(){
        fclose(fp);
    }
};