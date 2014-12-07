setClass("deeplearning", representation("VIRTUAL"))
setClass("sda", representation(backend="C++Object"), contains=c("deeplearning"))
setClass("da", representation(backend="C++Object"), contains=c("deeplearning"))
