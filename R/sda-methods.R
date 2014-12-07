setMethod("summary", 
          signature=c("sda"),
          function(object) return(object@backend$summary()))

setMethod("pretrain", 
          signature=c("sda"),
          function(object) return(object@backend$pretrain()))

setMethod("finetune", 
          signature=c("sda"),
          function(object) return(object@backend$finetune()))

setMethod("PretrainLearningRate",
          signature=c("sda"),
          function(object) {
            info <- summary(object)           
            return(info$PretrainLearningRate)
          })
          
setMethod("CorruptionLevel",
          signature=c("sda"),
          function(object) {
            info <- summary(object)           
            return(info$CorruptionLevel)
          })

setMethod("PretrainingEpochs",
          signature=c("sda"),
          function(object) {
            info <- summary(object)           
            return(info$PretrainingEpochs)
          })

setMethod("FinetuneLearningRate",
          signature=c("sda"),
          function(object) {
            info <- summary(object)           
            return(info$FinetuneLearningRate)
          })

setMethod("FinetuneEpochs",
          signature=c("sda"),
          function(object) {
            info <- summary(object)           
            return(info$FinetuneEpochs)
          })
          
setMethod("predict",
          signature=c("sda","matrix"),
          function(object,test) {
            return(object@backend$predict(test))
          })
          
setMethod("setPretrainLearningRate",
          signature=c("sda","numeric"),
          function(object, plr) {
            return(object@backend$setPretrainLearningRate(plr))
          })

setMethod("setPretrainEpochs",
          signature=c("sda","numeric"),
          function(object, pe) {
            return(object@backend$setPretrainEpochs(pe))
          })
          
setMethod("setFinetuneLearningRate",
          signature=c("sda","numeric"),
          function(object, flr) {
            return(object@backend$setFinetuneLearningRate(flr))
          })     
          
setMethod("setFinetuneEpochs",
          signature=c("sda","numeric"),
          function(object, fe) {
            return(object@backend$setFinetuneEpochs(fe))
          })                

setMethod("setCorruptionLevel",
          signature=c("sda","numeric"),
          function(object, cl) {
            return(object@backend$setCorruptionLevel(cl))
          })  

Rsda <- function(x, y, hidden){
    sdaModule <- new(Sda)
    sdaModule$init(x, y, hidden)
    return(new("sda",
               backend=sdaModule))

}
