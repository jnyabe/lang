object Timer2 {
  def oncePerSeocnd(callback: ()=> Unit) {
    while(true) { callback(); Thread sleep 1000 }
  }

  def main(args: Array[String]) {
    oncePerSeocnd(()=> println("time flies like an arrow..."))
  }
}
