auto garner(const auto& x, auto mods, auto mod=LINF){
    using u64 = std::uint_fast64_t;
    u64 v=0;
    mods.emplace_back(mod);
    vector<u64> coeffs(x.size()+1,1); // coeffs[i]v_i
    vector<u64> constants(x.size()+1,0);
    auto modinv=[](u64 x,u64 mod){
        u64 y=mod-2;
        auto ret=1;
        while(y>0) {
            if(y&1)(ret*=x)%=mod;
            (x*=x)%=mod;
            y>>=1;
        }
        return ret;
    };
    for(int i=0;i<(int)x.size();i++) {
        u64 v=(x[i]-constants[i])*modinv(coeffs[i],mods[i])%mods[i];
        if(v<0)v+=mods[i];
        for(int j=i+1;j<(int)x.size()+1;j++) {
            constants[j]=(constants[j]+coeffs[j]*v)%mods[j];
            coeffs[j]=(coeffs[j]*mods[i])%mods[j];
        }
    }
    return constants.back();
}