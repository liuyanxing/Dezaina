interface Struct {}
interface Message {}

interface Page extends Message, Struct {
}

type float = "float"

interface Document {
	id: string
	page: Array<Page>
    curPage: Page
    count: float
}