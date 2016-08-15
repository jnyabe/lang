package util
import play.api.libs.json.Json

case class Portal(name: String, x: Int, y: Int)
object Portal {
  implicit def jsonWrites = Json.writes[Portal]
  implicit def jsonReads = Json.reads[Portal]
}

