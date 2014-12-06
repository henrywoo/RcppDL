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

Rsda <- function(x, y, hidden){
    sdaModule <- new(Sda)
    sdaModule$init(x, y, hidden)
    return(new("sda",
               backend=sdaModule))

}
