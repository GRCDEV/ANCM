# TEST ALL PARAMETERS
#./ANCM_Lib_MacARM -S'1.1,1.2,1.3;2.1,2.2,2.3;1;0;7600;150.1'  -O'1.1,2.2,3.3' -NSEL, -MD, -V277.12 -A'0,1' -C'105.2,16' -F./NPD_Data/NPD_data_Test_JETF.csv -T5
# FIRST TEST -> Some parameters are set to default
./ANCM_Lib_MacARM -S'3141.5,0,3.3;3869.3,0,3.3;1;0;7500;149.8962'  -O'9842.5,1640.4,0' -NLAm, -MA,  -A'0,1' -F./NPD_Data/NPD_data_Test_JETF.csv -T7
