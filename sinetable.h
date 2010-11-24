static float sinetab[] = {
0.000000000000000,
0.012271538285720,
0.024541228522912,
0.036807222941359,
0.049067674327418,
0.061320736302209,
0.073564563599667,
0.085797312344440,
0.098017140329561,
0.110222207293883,
0.122410675199216,
0.134580708507126,
0.146730474455362,
0.158858143333861,
0.170961888760301,
0.183039887955141,
0.195090322016128,
0.207111376192219,
0.219101240156870,
0.231058108280671,
0.242980179903264,
0.254865659604515,
0.266712757474898,
0.278519689385053,
0.290284677254462,
0.302005949319228,
0.313681740398892,
0.325310292162263,
0.336889853392220,
0.348418680249435,
0.359895036534988,
0.371317193951838,
0.382683432365090,
0.393992040061048,
0.405241314004990,
0.416429560097637,
0.427555093430282,
0.438616238538528,
0.449611329654607,
0.460538710958240,
0.471396736825998,
0.482183772079123,
0.492898192229784,
0.503538383725718,
0.514102744193222,
0.524589682678469,
0.534997619887097,
0.545324988422046,
0.555570233019602,
0.565731810783613,
0.575808191417845,
0.585797857456439,
0.595699304492433,
0.605511041404326,
0.615231590580627,
0.624859488142386,
0.634393284163645,
0.643831542889791,
0.653172842953777,
0.662415777590172,
0.671558954847018,
0.680600997795453,
0.689540544737067,
0.698376249408973,
0.707106781186547,
0.715730825283819,
0.724247082951467,
0.732654271672413,
0.740951125354959,
0.749136394523459,
0.757208846506484,
0.765167265622459,
0.773010453362737,
0.780737228572094,
0.788346427626606,
0.795836904608883,
0.803207531480645,
0.810457198252595,
0.817584813151584,
0.824589302785025,
0.831469612302545,
0.838224705554838,
0.844853565249707,
0.851355193105265,
0.857728610000272,
0.863972856121587,
0.870086991108711,
0.876070094195407,
0.881921264348355,
0.887639620402854,
0.893224301195515,
0.898674465693954,
0.903989293123443,
0.909167983090522,
0.914209755703531,
0.919113851690058,
0.923879532511287,
0.928506080473215,
0.932992798834739,
0.937339011912575,
0.941544065183021,
0.945607325380521,
0.949528180593037,
0.953306040354194,
0.956940335732209,
0.960430519415566,
0.963776065795440,
0.966976471044852,
0.970031253194544,
0.972939952205560,
0.975702130038529,
0.978317370719628,
0.980785280403230,
0.983105487431216,
0.985277642388941,
0.987301418157858,
0.989176509964781,
0.990902635427780,
0.992479534598710,
0.993906970002356,
0.995184726672197,
0.996312612182778,
0.997290456678690,
0.998118112900149,
0.998795456205172,
0.999322384588350,
0.999698818696204,
0.999924701839145,
1.000000000000000,
0.999924701839145,
0.999698818696204,
0.999322384588350,
0.998795456205172,
0.998118112900149,
0.997290456678690,
0.996312612182778,
0.995184726672197,
0.993906970002356,
0.992479534598710,
0.990902635427780,
0.989176509964781,
0.987301418157858,
0.985277642388941,
0.983105487431216,
0.980785280403230,
0.978317370719628,
0.975702130038529,
0.972939952205560,
0.970031253194544,
0.966976471044852,
0.963776065795440,
0.960430519415566,
0.956940335732209,
0.953306040354194,
0.949528180593037,
0.945607325380521,
0.941544065183021,
0.937339011912575,
0.932992798834739,
0.928506080473216,
0.923879532511287,
0.919113851690058,
0.914209755703531,
0.909167983090522,
0.903989293123443,
0.898674465693954,
0.893224301195515,
0.887639620402854,
0.881921264348355,
0.876070094195407,
0.870086991108711,
0.863972856121587,
0.857728610000272,
0.851355193105265,
0.844853565249707,
0.838224705554838,
0.831469612302545,
0.824589302785025,
0.817584813151584,
0.810457198252595,
0.803207531480645,
0.795836904608884,
0.788346427626606,
0.780737228572095,
0.773010453362737,
0.765167265622459,
0.757208846506485,
0.749136394523459,
0.740951125354959,
0.732654271672413,
0.724247082951467,
0.715730825283819,
0.707106781186548,
0.698376249408973,
0.689540544737067,
0.680600997795453,
0.671558954847019,
0.662415777590172,
0.653172842953777,
0.643831542889791,
0.634393284163645,
0.624859488142386,
0.615231590580627,
0.605511041404326,
0.595699304492433,
0.585797857456439,
0.575808191417845,
0.565731810783613,
0.555570233019602,
0.545324988422046,
0.534997619887097,
0.524589682678469,
0.514102744193222,
0.503538383725718,
0.492898192229784,
0.482183772079123,
0.471396736825998,
0.460538710958240,
0.449611329654607,
0.438616238538528,
0.427555093430282,
0.416429560097637,
0.405241314004990,
0.393992040061048,
0.382683432365090,
0.371317193951838,
0.359895036534988,
0.348418680249435,
0.336889853392220,
0.325310292162263,
0.313681740398891,
0.302005949319228,
0.290284677254462,
0.278519689385053,
0.266712757474898,
0.254865659604515,
0.242980179903264,
0.231058108280671,
0.219101240156870,
0.207111376192219,
0.195090322016129,
0.183039887955141,
0.170961888760301,
0.158858143333861,
0.146730474455362,
0.134580708507126,
0.122410675199216,
0.110222207293883,
0.098017140329561,
0.085797312344440,
0.073564563599668,
0.061320736302208,
0.049067674327418,
0.036807222941359,
0.024541228522912,
0.012271538285720,
0.000000000000000,
-0.012271538285720,
-0.024541228522912,
-0.036807222941359,
-0.049067674327418,
-0.061320736302208,
-0.073564563599667,
-0.085797312344440,
-0.098017140329561,
-0.110222207293883,
-0.122410675199216,
-0.134580708507126,
-0.146730474455362,
-0.158858143333861,
-0.170961888760301,
-0.183039887955141,
-0.195090322016128,
-0.207111376192219,
-0.219101240156870,
-0.231058108280671,
-0.242980179903264,
-0.254865659604514,
-0.266712757474898,
-0.278519689385053,
-0.290284677254462,
-0.302005949319228,
-0.313681740398891,
-0.325310292162263,
-0.336889853392220,
-0.348418680249435,
-0.359895036534988,
-0.371317193951837,
-0.382683432365090,
-0.393992040061048,
-0.405241314004990,
-0.416429560097637,
-0.427555093430282,
-0.438616238538527,
-0.449611329654607,
-0.460538710958240,
-0.471396736825998,
-0.482183772079123,
-0.492898192229784,
-0.503538383725717,
-0.514102744193222,
-0.524589682678469,
-0.534997619887097,
-0.545324988422046,
-0.555570233019602,
-0.565731810783613,
-0.575808191417845,
-0.585797857456439,
-0.595699304492433,
-0.605511041404325,
-0.615231590580627,
-0.624859488142386,
-0.634393284163645,
-0.643831542889791,
-0.653172842953777,
-0.662415777590172,
-0.671558954847018,
-0.680600997795453,
-0.689540544737067,
-0.698376249408973,
-0.707106781186547,
-0.715730825283818,
-0.724247082951467,
-0.732654271672413,
-0.740951125354959,
-0.749136394523459,
-0.757208846506484,
-0.765167265622459,
-0.773010453362737,
-0.780737228572094,
-0.788346427626606,
-0.795836904608883,
-0.803207531480645,
-0.810457198252595,
-0.817584813151584,
-0.824589302785025,
-0.831469612302545,
-0.838224705554838,
-0.844853565249707,
-0.851355193105265,
-0.857728610000272,
-0.863972856121586,
-0.870086991108711,
-0.876070094195407,
-0.881921264348355,
-0.887639620402854,
-0.893224301195515,
-0.898674465693954,
-0.903989293123443,
-0.909167983090522,
-0.914209755703530,
-0.919113851690058,
-0.923879532511287,
-0.928506080473215,
-0.932992798834739,
-0.937339011912575,
-0.941544065183021,
-0.945607325380521,
-0.949528180593037,
-0.953306040354194,
-0.956940335732209,
-0.960430519415566,
-0.963776065795440,
-0.966976471044852,
-0.970031253194544,
-0.972939952205560,
-0.975702130038528,
-0.978317370719628,
-0.980785280403230,
-0.983105487431216,
-0.985277642388941,
-0.987301418157858,
-0.989176509964781,
-0.990902635427780,
-0.992479534598710,
-0.993906970002356,
-0.995184726672197,
-0.996312612182778,
-0.997290456678690,
-0.998118112900149,
-0.998795456205172,
-0.999322384588349,
-0.999698818696204,
-0.999924701839145,
-1.000000000000000,
-0.999924701839145,
-0.999698818696204,
-0.999322384588350,
-0.998795456205172,
-0.998118112900149,
-0.997290456678690,
-0.996312612182778,
-0.995184726672197,
-0.993906970002356,
-0.992479534598710,
-0.990902635427780,
-0.989176509964781,
-0.987301418157858,
-0.985277642388941,
-0.983105487431216,
-0.980785280403230,
-0.978317370719628,
-0.975702130038529,
-0.972939952205560,
-0.970031253194544,
-0.966976471044852,
-0.963776065795440,
-0.960430519415566,
-0.956940335732209,
-0.953306040354194,
-0.949528180593037,
-0.945607325380521,
-0.941544065183021,
-0.937339011912575,
-0.932992798834739,
-0.928506080473216,
-0.923879532511287,
-0.919113851690058,
-0.914209755703531,
-0.909167983090522,
-0.903989293123443,
-0.898674465693954,
-0.893224301195515,
-0.887639620402854,
-0.881921264348355,
-0.876070094195407,
-0.870086991108711,
-0.863972856121587,
-0.857728610000272,
-0.851355193105265,
-0.844853565249707,
-0.838224705554838,
-0.831469612302545,
-0.824589302785025,
-0.817584813151584,
-0.810457198252595,
-0.803207531480645,
-0.795836904608884,
-0.788346427626606,
-0.780737228572095,
-0.773010453362737,
-0.765167265622459,
-0.757208846506485,
-0.749136394523460,
-0.740951125354959,
-0.732654271672413,
-0.724247082951467,
-0.715730825283819,
-0.707106781186548,
-0.698376249408973,
-0.689540544737067,
-0.680600997795453,
-0.671558954847019,
-0.662415777590172,
-0.653172842953777,
-0.643831542889791,
-0.634393284163646,
-0.624859488142386,
-0.615231590580627,
-0.605511041404326,
-0.595699304492433,
-0.585797857456439,
-0.575808191417845,
-0.565731810783614,
-0.555570233019602,
-0.545324988422047,
-0.534997619887097,
-0.524589682678469,
-0.514102744193222,
-0.503538383725718,
-0.492898192229784,
-0.482183772079123,
-0.471396736825998,
-0.460538710958240,
-0.449611329654607,
-0.438616238538528,
-0.427555093430283,
-0.416429560097637,
-0.405241314004990,
-0.393992040061048,
-0.382683432365090,
-0.371317193951838,
-0.359895036534988,
-0.348418680249435,
-0.336889853392220,
-0.325310292162263,
-0.313681740398892,
-0.302005949319229,
-0.290284677254462,
-0.278519689385054,
-0.266712757474899,
-0.254865659604514,
-0.242980179903264,
-0.231058108280671,
-0.219101240156870,
-0.207111376192219,
-0.195090322016129,
-0.183039887955141,
-0.170961888760302,
-0.158858143333862,
-0.146730474455362,
-0.134580708507126,
-0.122410675199216,
-0.110222207293883,
-0.098017140329561,
-0.085797312344440,
-0.073564563599667,
-0.061320736302209,
-0.049067674327418,
-0.036807222941359,
-0.024541228522912,
-0.012271538285721
};


static inline int sinelu(float phase, float radius) 
{
  return (int) (sinetab[((int)(phase * 512)) % 512] * radius);
}


static inline int coslu(float phase, float radius) 
{
  return (int) (sinetab[((int)((phase + 0.25f) * 512)) % 512] * radius);
}

